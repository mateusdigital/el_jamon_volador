#!/usr/bin/env bash
##~---------------------------------------------------------------------------##
##                        _      _                 _   _                      ##
##                    ___| |_ __| |_ __ ___   __ _| |_| |_                    ##
##                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   ##
##                   \__ \ || (_| | | | | | | (_| | |_| |_                    ##
##                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   ##
##                                                                            ##
##  File      : bump_version.sh                                               ##
##  Project   : flappy_gb                                                     ##
##  Date      : May 25, 2020                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : stdmatt <stdmatt@pixelwizards.io>                             ##
##  Copyright : stdmatt - 2020                                                ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

##----------------------------------------------------------------------------##
## Imports                                                                    ##
##----------------------------------------------------------------------------##
source /usr/local/src/stdmatt/shellscript_utils/main.sh

##----------------------------------------------------------------------------##
## Variables                                                                  ##
##----------------------------------------------------------------------------##
SCRIPT_DIR="$(pw_get_script_dir)";

SRC_DIR="$(pw_abspath "${SCRIPT_DIR}/../game/include")";
HTML_DIR="$(pw_abspath "${SCRIPT_DIR}/../html")";

SRC_FILE="${SRC_DIR}/version.h";
HTML_FILE="${HTML_DIR}/index.html";


##----------------------------------------------------------------------------##
## Script                                                                     ##
##----------------------------------------------------------------------------##
BUMP_THE_VERSION="$(pw_get_program_path "bump-the-version")";
if [ -z "$BUMP_THE_VERSION" ]; then
    pw_log_fatal "Couldn't find (bump-the-version) program - Aborting...";
fi;


LINK_STR="<a href=\"https://stdmatt.com/deploy/games/el_jamon_volador/archive/el_ramon_volador_v";

"${BUMP_THE_VERSION}" "${SRC_FILE}"  "#define GAME_VERSION" bump "$1";
"${BUMP_THE_VERSION}" "${HTML_FILE}" "    v" bump "$1";
"${BUMP_THE_VERSION}" "${HTML_FILE}" "$LINK_STR" bump "$1";
