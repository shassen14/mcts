#!/usr/bin/env bash

SCRIPT_DIR=$(realpath $(dirname $0))
BUILD_DIR=${SCRIPT_DIR}/build

# function to make the build directory if it doesn't exist
make_build_dir() {
if [ ! -d ${BUILD_DIR} ]; then
  echo "Making the directory, ${BUILD_DIR}"
  mkdir ${BUILD_DIR}
fi
}

# Make and build the project
make_build_dir
cmake -B ${BUILD_DIR} ${SCRIPT_DIR}
cmake --build ${BUILD_DIR}
