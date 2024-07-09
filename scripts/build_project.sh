#!/usr/bin/env bash

SCRIPT_DIR=$(realpath $(dirname $0))
source ${SCRIPT_DIR}/variables.sh

# function to make the build directory if it doesn't exist
make_build_dir() {
if [ ! -d ${BUILD_DIR} ]; then
  echo "Making the directory, ${BUILD_DIR}"
  mkdir ${BUILD_DIR}
fi
}

# Make and build the project
make_build_dir
cmake -B ${BUILD_DIR} ${PROJECT_DIR}
cmake --build ${BUILD_DIR}
