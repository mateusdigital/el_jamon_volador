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
##  Copyright : stdmatt - 2019, 2020                                          ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

BUILD_DIR="${ROOT_DIR}/build";
DIST_DIR="${ROOT_DIR}/dist";

SOURCE_DIR="${ROOT_DIR}/game/src";
INCLUDE_DIR="${ROOT_DIR}/game/include";
LCC="";


##----------------------------------------------------------------------------##
## Script                                                                     ##
##----------------------------------------------------------------------------##
## @todo(stdmatt): Make the project compilers on GNU/Linux as well..
if [ "$(pw_os_get_simple_name)" == "$(PW_OS_OSX)" ]; then
    #notice(stdamtt):  GBDKDIR NEEDS TO END WITH A SLASH /
    export GBDKDIR="${ROOT_DIR}/game/third_party/osx/gbdk/";
    test -d "$GBDKDIR" ||            \
        pw_log_fatal                 \
            "GBDKDIR doesn't exists" \
            "GBDKDIR: ($GBDKDIR)";

    LCC="${GBDKDIR}/bin/lcc";
else
    pw_log_fatal "Can't build in non OSX hosts yet...";
fi;

##
## Build
echo "Cleaning build directory";
rm    -rf "$BUILD_DIR";
mkdir -p  "$BUILD_DIR";

FINAL_VERSION="$(bump-the-version \
    "${INCLUDE_DIR}/version.h"    \
    "#define GAME_VERSION"        \
    show                          \
)";

echo "Building $PROJECT_NAME - $FINAL_VERSION";
## Compile the game.
$LCC -o                                                       \
    ${BUILD_DIR}/${PROJECT_PACKAGE_NAME}_${FINAL_VERSION}.gb  \
    ${SOURCE_DIR}/*.c                                         \
    ${INCLUDE_DIR}/res/flappy.c


##
## Dist
test -z "$(pw_getopt_exists "--dist" "$@")" && exit;
echo "Creating the distribution artifact!!!";

echo "Cleaning dist directory";
rm    -rf "$DIST_DIR";
mkdir -p  "$DIST_DIR";

echo "Creating zip file";
ZIP_FILENAME="${PROJECT_PACKAGE_NAME}_v${FINAL_VERSION}.zip";
pw_pushd "${BUILD_DIR}";
    zip -r "${ZIP_FILENAME}" ".";
    mv "${ZIP_FILENAME}" "${DIST_DIR}";
pw_popd
