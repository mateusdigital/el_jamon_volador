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
##  File      : clean-everything.sh                                           ##
##  Project   : flappy_gb                                                     ##
##  Date      : 2023-06-02                                                    ##
##  License   : GPLv3                                                         ##
##  Author    : mateus.digital <hello@mateus.digital>                         ##
##  Copyright : mateus.digital - 2023                                         ##
##                                                                            ##
##  Description :                                                             ##
##    Cleans the build artifacts.                                             ##
##---------------------------------------------------------------------------~##

set -e; ## break on errors.

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)";
readonly ROOT_DIR="$(dirname "$SCRIPT_DIR")";

echo "$0 ==> Cleaning...";
rm -vrf "${ROOT_DIR}/build"; ## Game build
rm -vrf "${ROOT_DIR}/out";   ## Static Website
rm -vrf "${ROOT_DIR}/dist";  ## Distribution files.
echo "$0 ==> Done...";