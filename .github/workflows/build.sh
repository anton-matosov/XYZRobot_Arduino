#!/usr/bin/env bash

set -e
set -x

ROOT=$PWD
ARDUINO_SDK_PATH=$PWD/Arduino.app
mkdir -p build 
cd build
# cmake -DSDK_PATH_HINTS=$ARDUINO_SDK_PATH  ..
cmake -DSDK_PATH_HINTS=$ARDUINO_SDK_PATH -DCMAKE_TOOLCHAIN_FILE=${ROOT}/cmake/ArduinoToolchain.cmake ..
cmake --build . --target Bolide
