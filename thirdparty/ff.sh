#!/bin/bash
NDK=/opt/android-ndk-r15c
SYSROOT=$NDK/platforms/android-19/arch-x86/
TOOLCHAIN=$NDK/toolchains/x86-4.9/prebuilt/linux-x86_64
function build_one
{
./configure --prefix=$PREFIX --enable -pic --disable-shared --enable-static --disable-doc --disable-ffmpeg --disable-ffplay --disable-ffprobe --disable-ffserver --disable-avdevice --disable-doc --disable-symver --cross-prefix=$TOOLCHAIN/bin/i686-linux-android- --target-os=linux --arch=x86 --enable-cross-compile --sysroot=$SYSROOT --extra-cflags="-Os -fpic $ADDI_CFLAGS" --extra-ldflags="$ADDI_LDFLAGS" $ADDITIONAL_CONFIGURE_FLAG
make clean
make
make install
}
CPU=x86
PREFIX=/mnt/c/nordroid/nodeapp/x86/
ADDI_CFLAGS="-mx86"
build_one