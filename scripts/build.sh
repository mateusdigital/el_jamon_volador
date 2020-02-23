#!/usr/bin/env bash
##~---------------------------------------------------------------------------##
##                        _      _                 _   _                      ##
##                    ___| |_ __| |_ __ ___   __ _| |_| |_                    ##
##                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   ##
##                   \__ \ || (_| | | | | | | (_| | |_| |_                    ##
##                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   ##
##                                                                            ##
##  File      : build.sh                                                      ##
##  Project   : flappy_gb                                                     ##
##  Date      : Sep 22, 2019                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : stdmatt <stdmatt@pixelwizards.io>                             ##
##  Copyright : stdmatt 2019, 2020                                            ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

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

## @todo(stdmatt): Make the project compilers on GNU/Linux as well..
if [ $(pw_os_get_simple_name) == $(PW_OS_OSX) ]; then
    GBDKDIR="${PROJECT_DIR}/third_party/osx/gbdk";
    LCC="${GBDKDIR}/bin/lcc";
fi;

rm    -rf "$BUILD_DIR";
mkdir -p  "$BUILD_DIR";

$LCC -o $BUILD_DIR/flappy.gb  $SRC_DIR/*.c  $INCLUDE_DIR/res/flappy.c

if [ "$1" == "--run" ]; then
    mgba -3 ./build/flappy.gb
fi;
