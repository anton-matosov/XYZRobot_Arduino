#!/usr/bin/env bash

set -e
set -x

ARDUINO_SDK_PATH=$PWD/Arduino.app
mkdir -p build 
cd build
cmake -DSDK_PATH_HINTS=$ARDUINO_SDK_PATH ..

cmake --build . --target Bolide
