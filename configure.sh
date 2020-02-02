#!/usr/bin/env bash

SCRIPT_DIR=$(dirname ${BASH_SOURCE[0]})

conan install $SCRIPT_DIR --profile="$SCRIPT_DIR/profile.txt"
