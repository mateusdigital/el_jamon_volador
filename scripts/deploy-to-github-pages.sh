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
##  File      : deploy-to-github-pages.sh                                     ##
##  Project   : flappy_gb                                                     ##
##  Date      : May 05, 2023                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : mateus.digital <hello@mateus.digital>                         ##
##  Copyright : mateus.digital - 2023                                         ##
##                                                                            ##
##  Description :                                                             ##
##    To publish in github pages we need to:                                  ##
##      1 - Check to the publish branch.                                      ##
##      2 - Copy the needed resources to docs/                                ##
##      3 - Get info of current version and build number.                     ##
##      4 - Insert build and version info into the index.html                 ##
##      5 - Make a commit (push is manual)                                    ##
##---------------------------------------------------------------------------~##


readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)";
readonly ROOT_DIR="$(dirname "$SCRIPT_DIR")";


## retrive build and version.
readonly VERSION="$(git describe --abbrev=0 --tags)";
readonly CURR_BUILD="$(cat "${ROOT_DIR}/.buildno")";
readonly NEXT_BUILD="$(( CURR_BUILD + 1 ))";
readonly DATE="$(date +'%H:%M:%S %d-%m-%Y - %Z')";


git checkout publish;

## clean dir.
rm -rf   "${ROOT_DIR}/docs/";
mkdir -p "${ROOT_DIR}/docs/";

## copy things.
cp -R "${ROOT_DIR}/html/"* \
    "${ROOT_DIR}/docs/"

## remove git repos from docs/
find "$ROOT_DIR/docs" -iname "*.git*" -type d | xargs rm -rf;


## update the index with version and build number.
cat "${ROOT_DIR}/docs/index.html"         \
    | sed s/"_version_"/"${VERSION}"/g    \
    | sed s/"_build_"/"${NEXT_BUILD}"/g   \
    > "${ROOT_DIR}/docs/index.html.tmp"   \
    && mv                                 \
        "${ROOT_DIR}/docs/index.html.tmp" \
        "${ROOT_DIR}/docs/index.html"     \
    ;

echo "${NEXT_BUILD}" > "${ROOT_DIR}/.buildno";

## Commit
git add docs/;
git commit -m "$0 - build: $NEXT_BUILD - $DATE";
