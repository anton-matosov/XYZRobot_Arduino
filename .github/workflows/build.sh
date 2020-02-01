#!/usr/bin/env bash

set -e
set -x

curl --version || echo "no curl"
git --version || echo "no git"
cmake --version || echo "no cmake"
make --version || echo "no make"
ninja --version || echo "no ninja"

ROOT=$PWD
ARDUINO_SDK_PATH=$PWD/Arduino.app
cat $ARDUINO_SDK_PATH/Contents/Java/lib/version.txt

mkdir -p build 
cd build
# cmake -DSDK_PATH_HINTS=$ARDUINO_SDK_PATH  ..
cmake -DSDK_PATH_HINTS=$ARDUINO_SDK_PATH -DCMAKE_TOOLCHAIN_FILE=${ROOT}/cmake/ArduinoToolchain.cmake ..
cmake --build . --target Bolide
