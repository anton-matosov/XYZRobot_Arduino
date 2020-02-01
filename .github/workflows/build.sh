#!/usr/bin/env bash

set -e
set -x

exit 0 # Toolchain doesn't work on CI well... Wait for conan integration

curl --version || echo "no curl"
git --version || echo "no git"
cmake --version || echo "no cmake"
make --version || echo "no make"
ninja --version || echo "no ninja"

ROOT=$PWD
ARDUINO_SDK_PATH=$PWD/Arduino.app/Contents/Java
cat $ARDUINO_SDK_PATH/lib/version.txt

mkdir -p build 
cd build
cmake -DARDUINO_SDK_PATH=$ARDUINO_SDK_PATH ..
cmake --build . --target Bolide
