#!/bin/bash

set -e
#set -x

function abspath() {
    # generate absolute path from relative path
    # $1     : relative filename
    # return : absolute path
    if [ -d "$1" ]; then
        # dir
        (cd "$1"; pwd)
    elif [ -f "$1" ]; then
        # file
        if [[ $1 == */* ]]; then
            echo "$(cd "${1%/*}"; pwd)/${1##*/}"
        else
            echo "$(pwd)/$1"
        fi
    fi
}

rootDir="$(abspath $(dirname $0)/..)"

mkdir -p "$HOME/Documents/Arduino/hardware"
ln -sf "$rootDir/XYZSharedProjects/hardware/XYZrobot/1.6" "$HOME/Documents/Arduino/hardware/XYZrobot"

mkdir -p "$HOME/Documents/Arduino/libraries"
ln -sf "$rootDir/XYZSharedProjects/libraries/BOLIDE_Player" "$HOME/Documents/Arduino/libraries/BOLIDE_Player"


