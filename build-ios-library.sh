DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null && pwd )"
echo "$DIR"

git submodule init $DIR
git submodule update --init --recursive $DIR

#---- Create Dirs ----
rm -rf "$DIR/out"
mkdir -p "$DIR/out"
mkdir -p "$DIR/out/armv7"
mkdir -p "$DIR/out/armv7s"
mkdir -p "$DIR/out/arm64"
mkdir -p "$DIR/out/i386"
mkdir -p "$DIR/out/x86_64"
mkdir -p "$DIR/out/temp"

#---- Build for armv7 ----
xcodebuild -project "$DIR/libpd.xcodeproj" -target "libpd-ios" OTHER_CFLAGS="-DPD -DUSEAPI_DUMMY -DHAVE_UNISTD_H -DLIBPD_EXTRA -DUSE_PD_MAIN -fcommon -fembed-bitcode" CLANG_ENABLE_MODULE_DEBUGGING=NO ONLY_ACTIVE_ARCH=NO -sdk iphoneos -arch armv7
cp -f -v "$DIR/build/Release-iphoneos/libpd-ios.a" "$DIR/out/armv7/libpd-ios.a"

#---- Build for armv7s ----
xcodebuild -project "$DIR/libpd.xcodeproj" -target "libpd-ios" OTHER_CFLAGS="-DPD -DUSEAPI_DUMMY -DHAVE_UNISTD_H -DLIBPD_EXTRA -DUSE_PD_MAIN -fcommon -fembed-bitcode" CLANG_ENABLE_MODULE_DEBUGGING=NO ONLY_ACTIVE_ARCH=NO -sdk iphoneos -arch armv7s
cp -f -v "$DIR/build/Release-iphoneos/libpd-ios.a" "$DIR/out/armv7s/libpd-ios.a"

#---- Build for arm64 ----
xcodebuild -project "$DIR/libpd.xcodeproj" -target "libpd-ios" OTHER_CFLAGS="-DPD -DUSEAPI_DUMMY -DHAVE_UNISTD_H -DLIBPD_EXTRA -DUSE_PD_MAIN -fcommon -fembed-bitcode" CLANG_ENABLE_MODULE_DEBUGGING=NO ONLY_ACTIVE_ARCH=NO -sdk iphoneos -arch arm64
cp -f -v "$DIR/build/Release-iphoneos/libpd-ios.a" "$DIR/out/arm64/libpd-ios.a"

#---- Build for i386 ----
xcodebuild -project "$DIR/libpd.xcodeproj" -target "libpd-ios" OTHER_CFLAGS="-DPD -DUSEAPI_DUMMY -DHAVE_UNISTD_H -DLIBPD_EXTRA -DUSE_PD_MAIN -fcommon  -fembed-bitcode" CLANG_ENABLE_MODULE_DEBUGGING=NO -sdk iphonesimulator -arch i386
cp -f -v "$DIR/build/Release-iphonesimulator/libpd-ios.a" "$DIR/out/i386/libpd-ios.a"

#---- Build for x86_64 ----
xcodebuild -project "$DIR/libpd.xcodeproj" -target "libpd-ios" OTHER_CFLAGS="-DPD -DUSEAPI_DUMMY -DHAVE_UNISTD_H -DLIBPD_EXTRA -DUSE_PD_MAIN -fcommon  -fembed-bitcode" LANG_ENABLE_MODULE_DEBUGGING=NO -sdk iphonesimulator -arch x86_64
cp -f -v "$DIR/build/Release-iphonesimulator/libpd-ios.a" "$DIR/out/x86_64/libpd-ios.a"

#---- Combine architectures with lipo ----
lipo -create -output "$DIR/out/temp/libpd-ios_1.a" "$DIR/out/armv7/libpd-ios.a" "$DIR/out/armv7s/libpd-ios.a"
lipo -create -output "$DIR/out/temp/libpd-ios_2.a" "$DIR/out/temp/libpd-ios_1.a" "$DIR/out/arm64/libpd-ios.a"
lipo -create -output "$DIR/out/temp/libpd-ios_3.a" "$DIR/out/temp/libpd-ios_2.a" "$DIR/out/i386/libpd-ios.a"
lipo -create -output "$DIR/out/temp/libpd-ios_4.a" "$DIR/out/temp/libpd-ios_3.a" "$DIR/out/x86_64/libpd-ios.a"

#---- Copy final library ----
cp -f -v "$DIR/out/temp/libpd-ios_4.a" "$DIR/out/libpd-ios.a"
