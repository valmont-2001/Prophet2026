# Building Prophet2012 on macOS

The Mac version uses wxWidgets 3.2 (Cocoa) instead of 2.8 and runs natively on Apple Silicon and Intel (universal binary, macOS 12 or later). All libraries are linked statically.

Requirements: Xcode and CMake (e.g. `brew install cmake`).

Open `Prophet2012.xcodeproj` in Xcode and build the scheme `Prophet2012`. The target `ThirdParty` runs `scripts/build-thirdparty-mac.sh` first, which downloads and builds the third party libraries into `ThirdParty/` (not part of the repository):

- wxWidgets 3.2.12
- PortAudio 19.7.0
- PortMidi 2.0.8
- libsamplerate 0.2.2

The first build takes several minutes (wxWidgets), later builds skip this step. The script can also be run by hand; `--clean` rebuilds everything.

Command line build:

    xcodebuild -project Prophet2012.xcodeproj -scheme Prophet2012 -configuration Release -derivedDataPath build -destination 'generic/platform=macOS' build

The app is then in `build/Build/Products/Release/Prophet2012.app`.

The Xcode project is generated from `project.yml` with [XcodeGen](https://github.com/yonaskolb/XcodeGen) (`xcodegen generate`). Mac specific adaptions of the wxFormBuilder layout are in `SRCDIR/macstyle.mm`.

## Disk image

    scripts/make-dmg-mac.sh

builds the Release version and creates `Prophet2012.dmg` in the project root with the app, a link to `/Applications` and the README. With `--no-build` the already built app is packed.

The app is only ad-hoc signed. On other Macs Gatekeeper blocks the first start; open it with right click → Open, or allow it in System Settings → Privacy & Security.
