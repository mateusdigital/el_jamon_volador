#!/usr/bin/env bash
##~---------------------------------------------------------------------------##
##                        _      _                 _   _                      ##
##                    ___| |_ __| |_ __ ___   __ _| |_| |_                    ##
##                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   ##
##                   \__ \ || (_| | | | | | | (_| | |_| |_                    ##
##                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   ##
##                                                                            ##
##  File      : build_game.sh                                                 ##
##  Project   : flappy_gb                                                     ##
##  Date      : Sep 22, 2019                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : stdmatt <stdmatt@pixelwizards.io>                             ##
##  Copyright : stdmatt 2019, 2020                                            ##
##                                                                            ##
##  Description :                                                             ##
##    Scripts to build and run the game in the emulator.                      ##
##---------------------------------------------------------------------------~##

##----------------------------------------------------------------------------##
## Imports                                                                    ##
##----------------------------------------------------------------------------##
source /usr/local/src/stdmatt/shellscript_utils/main.sh


##----------------------------------------------------------------------------##
## Vars                                                                       ##
##----------------------------------------------------------------------------##
SCRIPT_DIR=$(pw_get_script_dir);

PROJECT_DIR=$(pw_abspath ${SCRIPT_DIR}/..);

BUILD_DIR="${PROJECT_DIR}/build/game";

GAME_DIR="${PROJECT_DIR}/game";
INCLUDE_DIR="${GAME_DIR}/include";
SRC_DIR="${GAME_DIR}/src";


##----------------------------------------------------------------------------##
## Functions                                                                  ##
##----------------------------------------------------------------------------##
get_game_version()
{
    local VERSION=$(cat "${GAME_DIR}/include/version.h" | grep "GAME_VERSION");
    local CLEAN_VERSION="$(pw_string_replace $VERSION \" "")"

    echo "$CLEAN_VERSION";
}


##----------------------------------------------------------------------------##
## Script                                                                      ##
##----------------------------------------------------------------------------##
cd "$PROJECT_DIR";

## @todo(stdmatt): Make the project compilers on GNU/Linux as well..
if [ $(pw_os_get_simple_name) == $(PW_OS_OSX) ]; then
    #notice(stdamtt):  GBDKDIR NEEDS TO END WITH A SLASH /
    export GBDKDIR="${GAME_DIR}/third_party/osx/gbdk/";
    test -d "$GBDKDIR" ||            \
        pw_log_fatal                 \
            "GBDKDIR doesn't exists" \
            "GBDKDIR: ($GBDKDIR)";

    LCC="${GBDKDIR}/bin/lcc";
fi;

## Clean the build directory.
# rm    -rf "$BUILD_DIR";
mkdir -p  "$BUILD_DIR";

## Copyile the game.
GAME_VERSION=$(pw_string_replace $(get_game_version) "." "_");
$LCC -o                                           \
    ${BUILD_DIR}/el_ramon_vol_${GAME_VERSION}.gb  \
    ${SRC_DIR}/*.c                                \
    ${INCLUDE_DIR}/res/flappy.c

if [ "$1" == "--run" ]; then
    mgba -3 ./build/flappy.gb
fi;
