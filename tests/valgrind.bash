#!/usr/bin/env bash

# Assuming this file will be in the tests directory to run tests
SCRIPT_DIR=$(realpath $(dirname $0))
LOG_FILE=valgrind-out.txt

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=${LOG_FILE} \
         ${SCRIPT_DIR}/tests
