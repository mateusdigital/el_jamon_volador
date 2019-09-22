#!/usr/bin/env bash

##----------------------------------------------------------------------------##
## Imports                                                                    ##
##----------------------------------------------------------------------------##
source /usr/local/src/stdmatt/shellscript_utils/main.sh


##----------------------------------------------------------------------------##
## Vars                                                                       ##
##----------------------------------------------------------------------------##
SCRIPT_DIR=$(pw_get_script_dir);
PROJECT_DIR=$(pw_realpath $SCRIPT_DIR/..);
BUILD_DIR="$PROJECT_DIR/build";
INCLUDE_DIR="$PROJECT_DIR/include";
SRC_DIR="$PROJECT_DIR/src";


##----------------------------------------------------------------------------##
## Script                                                                      ##
##----------------------------------------------------------------------------##
cd "$PROJECT_DIR";

rm    -rf "$BUILD_DIR";
mkdir -p  "$BUILD_DIR";
lcc -o $BUILD_DIR/flappy.gb  $SRC_DIR/*.c  $INCLUDE_DIR/res/flappy.c

if [ "$1" == "--run" ]; then
    mgba -3 ./build/flappy.gb
fi;
