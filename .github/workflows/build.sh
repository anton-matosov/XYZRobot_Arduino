#!/usr/bin/env bash

set -e
set -x

rm -rf build
mkdir build
cd build

conan install --profile=../profile.txt ..

source ./activate.sh
source ./activate_build.sh

cmake -G Ninja .. -DCMAKE_TOOLCHAIN_FILE=$CONAN_CMAKE_TOOLCHAIN_FILE
ninja Bolide
