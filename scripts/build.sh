#!/usr/bin/env bash

set -e
set -x

cd build
ninja $@
