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
##  File      : full-build.sh                                                 ##
##  Project   : el_jamon_volador                                              ##
##  Date      : 2023-06-06                                                    ##
##  License   : GPLv3                                                         ##
##  Author    : mateus.digital <hello@mateus.digital>                         ##
##  Copyright : mateus.digital - 2023                                         ##
##                                                                            ##
##  Description :                                                             ##
##    Perform a full build - just to make easier...                           ##
##---------------------------------------------------------------------------~##

set -e ## break on errors...

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)";
readonly ROOT_DIR="$(dirname "$SCRIPT_DIR")";

${ROOT_DIR}/scripts/clean-everything.sh

${ROOT_DIR}/scripts/build-game.sh
${ROOT_DIR}/scripts/generate-release-zip.sh
${ROOT_DIR}/scripts/build-static.sh