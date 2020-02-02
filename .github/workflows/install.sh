#!/usr/bin/env bash

curl --version || echo "no curl"
git --version || echo "no git"
cmake --version || echo "no cmake"
make --version || echo "no make"
ninja --version || echo "no ninja"
python --version
pip --version

pip install conan

conan remote add anton https://api.bintray.com/conan/anton-matosov/general

