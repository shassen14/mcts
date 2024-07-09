#!/usr/bin/env bash

# TODO: rename this to valgrind_exe where the argument given will be
# the execuable that the developer wants to test.
# TODO: need to add required shell arguments to do this

# Source the general variables needed for directory paths
SCRIPT_DIR=$(realpath $(dirname $0))
source ${SCRIPT_DIR}/variables.sh

LOG_FILE=valgrind-out.txt

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=${LOG_FILE} \
         ${BUILD_DIR}/tests
