#!/bin/bash
#
# Downloads and builds the third party libraries of Prophet2012 for macOS as
# static universal (arm64 + x86_64) libraries:
#
#   wxWidgets, PortAudio, PortMidi, libsamplerate
#
# Everything ends up in ThirdParty/ (not part of the repository):
#   ThirdParty/downloads   source archives (checked by SHA-256)
#   ThirdParty/src         unpacked sources
#   ThirdParty/build       build directories
#   ThirdParty/install     headers and static libraries used by the Xcode project
#
# The Xcode project runs this script automatically (target "ThirdParty"), it can
# also be started by hand. Libraries already built are skipped.
#
# Usage: scripts/build-thirdparty-mac.sh [--clean]
#
# Requirements: Xcode command line tools, CMake (e.g. "brew install cmake")

set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
TP="$ROOT/ThirdParty"
DOWNLOADS="$TP/downloads"
SRC="$TP/src"
BUILD="$TP/build"
PREFIX="$TP/install"

DEPLOYMENT_TARGET="12.0"
ARCHS="arm64;x86_64"
JOBS="$(sysctl -n hw.ncpu)"

WX_VERSION="3.2.12"
WX_URL="https://github.com/wxWidgets/wxWidgets/releases/download/v$WX_VERSION/wxWidgets-$WX_VERSION.tar.bz2"
WX_SHA256="a62719bb5e1dcc41c1a6fc1eecd499c7ee8521f70402c7b1bb3342a1e16344e0"

PORTAUDIO_VERSION="19.7.0"
PORTAUDIO_URL="https://github.com/PortAudio/portaudio/archive/refs/tags/v$PORTAUDIO_VERSION.tar.gz"
PORTAUDIO_SHA256="5af29ba58bbdbb7bbcefaaecc77ec8fc413f0db6f4c4e286c40c3e1b83174fa0"

PORTMIDI_VERSION="2.0.8"
PORTMIDI_URL="https://github.com/PortMidi/portmidi/archive/refs/tags/v$PORTMIDI_VERSION.tar.gz"
PORTMIDI_SHA256="f21201d4cc233638d7bb6ee29ee6dece54f6c9c1aeb7989bc978001caaf2f666"

SAMPLERATE_VERSION="0.2.2"
SAMPLERATE_URL="https://github.com/libsndfile/libsamplerate/releases/download/$SAMPLERATE_VERSION/libsamplerate-$SAMPLERATE_VERSION.tar.xz"
SAMPLERATE_SHA256="3258da280511d24b49d6b08615bbe824d0cacc9842b0e4caf11c52cf2b043893"


# Xcode exports its build settings (SDKROOT, ARCHS, ...) to script phases. They
# confuse configure/CMake, so restart with a clean environment.
if [ -n "${XCODE_VERSION_ACTUAL:-}" ] && [ -z "${PROPHET_CLEAN_ENV:-}" ]; then
   exec env -i PROPHET_CLEAN_ENV=1 HOME="$HOME" TERM="${TERM:-dumb}" \
      PATH="/usr/bin:/bin:/usr/sbin:/sbin:/opt/homebrew/bin:/usr/local/bin" \
      /bin/bash "$0" "$@"
fi

if [ "${1:-}" = "--clean" ]; then
   rm -rf "$SRC" "$BUILD" "$PREFIX"
fi

command -v cmake >/dev/null || { echo "error: CMake not found, install it e.g. with 'brew install cmake'" >&2; exit 1; }

mkdir -p "$DOWNLOADS" "$SRC" "$BUILD" "$PREFIX"

# fetch <name> <url> <sha256> -> unpacks into $SRC/<name>
fetch()
{
   local name="$1" url="$2" sha="$3"
   local archive="$DOWNLOADS/$name-${url##*/}"
   if [ ! -f "$archive" ] || [ "$(shasum -a 256 "$archive" | cut -d' ' -f1)" != "$sha" ]; then
      echo "--- downloading $name"
      curl -fL --retry 3 -o "$archive.part" "$url"
      mv "$archive.part" "$archive"
   fi
   if [ "$(shasum -a 256 "$archive" | cut -d' ' -f1)" != "$sha" ]; then
      echo "error: checksum mismatch for $archive" >&2
      exit 1
   fi
   rm -rf "$SRC/$name"
   mkdir -p "$SRC/$name"
   tar -xf "$archive" -C "$SRC/$name" --strip-components 1
}

# done_stamp <name> <version>: true if this version is already installed
is_built() { [ -f "$PREFIX/.built-$1-$2" ]; }
mark_built() { rm -f "$PREFIX"/.built-"$1"-*; touch "$PREFIX/.built-$1-$2"; }

cmake_build()
{
   local name="$1"; shift
   rm -rf "$BUILD/$name"
   cmake -S "$SRC/$name" -B "$BUILD/$name" \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX="$PREFIX" \
      -DCMAKE_OSX_ARCHITECTURES="$ARCHS" \
      -DCMAKE_OSX_DEPLOYMENT_TARGET="$DEPLOYMENT_TARGET" \
      -DBUILD_SHARED_LIBS=OFF \
      "$@"
   cmake --build "$BUILD/$name" --parallel "$JOBS"
   cmake --install "$BUILD/$name"
}


if ! is_built portaudio "$PORTAUDIO_VERSION"; then
   echo "=== PortAudio $PORTAUDIO_VERSION"
   fetch portaudio "$PORTAUDIO_URL" "$PORTAUDIO_SHA256"
   cmake_build portaudio -DPA_BUILD_SHARED=OFF -DPA_BUILD_STATIC=ON -DPA_BUILD_TESTS=OFF -DPA_BUILD_EXAMPLES=OFF
   mark_built portaudio "$PORTAUDIO_VERSION"
fi

if ! is_built portmidi "$PORTMIDI_VERSION"; then
   echo "=== PortMidi $PORTMIDI_VERSION"
   fetch portmidi "$PORTMIDI_URL" "$PORTMIDI_SHA256"
   cmake_build portmidi -DBUILD_PORTMIDI_TESTS=OFF -DBUILD_JAVA_NATIVE_INTERFACE=OFF
   mark_built portmidi "$PORTMIDI_VERSION"
fi

if ! is_built samplerate "$SAMPLERATE_VERSION"; then
   echo "=== libsamplerate $SAMPLERATE_VERSION"
   fetch samplerate "$SAMPLERATE_URL" "$SAMPLERATE_SHA256"
   cmake_build samplerate -DBUILD_TESTING=OFF -DLIBSAMPLERATE_EXAMPLES=OFF -DLIBSAMPLERATE_INSTALL=ON
   mark_built samplerate "$SAMPLERATE_VERSION"
fi

if ! is_built wxwidgets "$WX_VERSION"; then
   echo "=== wxWidgets $WX_VERSION (takes a while)"
   fetch wxwidgets "$WX_URL" "$WX_SHA256"
   rm -rf "$BUILD/wxwidgets"
   mkdir -p "$BUILD/wxwidgets"
   (
      cd "$BUILD/wxwidgets"
      # monolithic static library, all image/compression libraries built in so
      # that the app only depends on system frameworks
      "$SRC/wxwidgets/configure" \
         --prefix="$PREFIX" \
         --with-osx_cocoa \
         --with-macosx-version-min="$DEPLOYMENT_TARGET" \
         --enable-universal_binary="${ARCHS//;/,}" \
         --disable-shared \
         --enable-monolithic \
         --enable-unicode \
         --disable-debug \
         --disable-sys-libs \
         --with-libpng=builtin --with-libjpeg=builtin --with-libtiff=builtin \
         --with-zlib=builtin --with-expat=builtin --with-regex=builtin \
         --without-liblzma \
         --disable-webview --disable-mediactrl --disable-stc
      make -j"$JOBS"
      make install
   )
   mark_built wxwidgets "$WX_VERSION"
fi

touch "$PREFIX/.built-all"
echo "Third party libraries are ready in $PREFIX"
