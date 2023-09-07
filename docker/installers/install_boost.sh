#!/usr/bin/env bash

set -e

VERSION="1_74_0"
FOLDER_NAME="boost_${VERSION}"
PKG_NAME="${FOLDER_NAME}.tar.bz2"
DOWNLOAD_LINK="https://boostorg.jfrog.io/artifactory/main/release/${VERSION//_/.}/source/${PKG_NAME}"

wget -c "${DOWNLOAD_LINK}"

tar xjf "${PKG_NAME}"

pushd ${FOLDER_NAME}
    ./bootstrap.sh
    ./b2 -d+2 -q \
         --build-type=complete \
         --layout=tagged \
         variant=release \
         link=shared \
         threading=multi \
         install
popd

rm -rf ${FOLDER_NAME}
rm -rf ${PKG_NAME}
