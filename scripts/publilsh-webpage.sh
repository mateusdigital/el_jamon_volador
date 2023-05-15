#!/usr/bin/env bash

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)";
readonly ROOT_DIR="$(dirname "$SCRIPT_DIR")";

rm -rf "${ROOT_DIR}/docs";
mkdir -p "${ROOT_DIR}/docs";

cp -R "${ROOT_DIR}"/html/* "${ROOT_DIR}"/docs;

echo "$0 done...";