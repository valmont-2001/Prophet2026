#!/bin/bash
#
# Builds the Release version of Prophet2012 and packs it into a disk image
# Prophet2012.dmg (app plus a link to /Applications for drag & drop install).
#
# Usage: scripts/make-dmg-mac.sh [--no-build]
#
#   --no-build   use the already built app in build/Build/Products/Release
#
# The resulting image is written to Prophet2012.dmg in the project root.

set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD="$ROOT/build"
APP="$BUILD/Build/Products/Release/Prophet2012.app"
DMG="$ROOT/Prophet2012.dmg"
VOLUME_NAME="Prophet 2012"

if [ "${1:-}" != "--no-build" ]; then
   echo "=== building Release"
   xcodebuild -project "$ROOT/Prophet2012.xcodeproj" -scheme Prophet2012 \
      -configuration Release -derivedDataPath "$BUILD" \
      -destination 'generic/platform=macOS' build | grep -E "error:|warning: .*Prophet2012|BUILD" || true
fi

if [ ! -d "$APP" ]; then
   echo "error: $APP not found, build it first" >&2
   exit 1
fi

echo "=== creating $DMG"
STAGING="$(mktemp -d)"
trap 'rm -rf "$STAGING"' EXIT

cp -R "$APP" "$STAGING/"
ln -s /Applications "$STAGING/Applications"
cp "$ROOT/README.md" "$STAGING/README.md"

rm -f "$DMG"
hdiutil create -volname "$VOLUME_NAME" -srcfolder "$STAGING" -fs HFS+ \
   -format UDZO -imagekey zlib-level=9 -ov "$DMG" >/dev/null
hdiutil verify "$DMG" >/dev/null

echo "Disk image ready: $DMG"
