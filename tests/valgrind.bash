#!/usr/bin/env bash

# Assuming this file will be in the tests directory to run tests
SCRIPT_DIR=$(realpath $(dirname $0))

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ${SCRIPT_DIR}/all_tests
