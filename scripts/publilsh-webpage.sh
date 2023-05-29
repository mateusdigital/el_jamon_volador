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
##  File      : publish.sh                                                      ##
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
##    The PROJECT_VERSION needs to be updated to new releases.                ##
##---------------------------------------------------------------------------~##


readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)";
readonly ROOT_DIR="$(dirname "$SCRIPT_DIR")";

rm -rf "${ROOT_DIR}/docs";
mkdir -p "${ROOT_DIR}/docs";

cp -R "${ROOT_DIR}"/html/* "${ROOT_DIR}"/docs;

echo "$0 done...";