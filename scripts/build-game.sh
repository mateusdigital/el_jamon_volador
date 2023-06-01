#!/usr/bin/env bash
##~---------------------------------------------------------------------------##
##                               *       +                                    ##
##                         '                  |                               ##
##                     ()    .-.,="``"=.    - o -                             ##
##                           '=/_       \     |                               ##
##                        *   |  '=._    |                                    ##
##                             \     `=./`,        '                          ##
##                          .   '=.__.=' `='      *                           ##
##                 +                         +                                ##
##                      O      *        '       .                             ##
##                                                                            ##
##  File      : build-game.sh                                                 ##
##  Project   : flappy_gb                                                     ##
##  Date      : Sep 22, 2019                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : mateus.digital <hello@mateus.digital>                         ##
##  Copyright : mateus.digital - 2019, 2020, 2023                             ##
##                                                                            ##
##  Description :                                                             ##
##    This script builds the game boy version of El Jamon Volador.            ##
##    As 29/05/23 it only can be built in macOS hosts, since the              ##
##    new version of the compiler on GNU doesn't produce a valid binary.      ##
##                                                                            ##
##---------------------------------------------------------------------------~##

##----------------------------------------------------------------------------##
## Variables                                                                  ##
##----------------------------------------------------------------------------##
##------------------------------------------------------------------------------
readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)";
readonly ROOT_DIR="$(dirname "$SCRIPT_DIR")";

##------------------------------------------------------------------------------
readonly BUILD_DIR="${ROOT_DIR}/build";
readonly DIST_DIR="${ROOT_DIR}/dist";
readonly HTML_DIR="${ROOT_DIR}/html";

readonly SOURCE_DIR="${ROOT_DIR}/game/src";
readonly INCLUDE_DIR="${ROOT_DIR}/game/include";

##------------------------------------------------------------------------------
readonly PROJECT_PACKAGE_NAME="el-jamon-volador";
readonly PROJECT_VERSION="$(git describe --abbrev=0 --tags)"
readonly FULL_PACKAGE_NAME="${PROJECT_PACKAGE_NAME}_${PROJECT_VERSION}.gb";


##----------------------------------------------------------------------------##
## Setup Compiler                                                             ##
##----------------------------------------------------------------------------##
## @todo(stdmatt): Make the project compilers on GNU/Linux as well..
if [ -n "$(uname -s | grep "Darwin")" ]; then
    #notice(stdamtt):  GBDKDIR NEEDS TO END WITH A SLASH /
    export GBDKDIR="${ROOT_DIR}/game/third_party/osx/gbdk/";
    if [ ! -d "$GBDKDIR" ]; then
        echo "GBDKDIR doesn't exists GBDKDIR: ($GBDKDIR)";
        exit 1;
    fi;

    export LCC="${GBDKDIR}/bin/lcc";
else
    echo "Can't build in non OSX hosts yet...";
    exit 1;
fi;


##----------------------------------------------------------------------------##
## Build                                                                      ##
##----------------------------------------------------------------------------##
echo "Cleaning build directory";
rm    -rf "$BUILD_DIR";
mkdir -p  "$BUILD_DIR";

echo "Building $PROJECT_NAME - $PROJECT_VERSION";

## Compile the game.
$LCC -o                               \
    ${BUILD_DIR}/${FULL_PACKAGE_NAME} \
    ${SOURCE_DIR}/*.c                 \
    ${INCLUDE_DIR}/res/flappy.c
