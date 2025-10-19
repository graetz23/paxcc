#!/bin/bash
#
# MIT License
#
# Copyright (c) 2017-2025 Christian (graetz23@gmail.com)
# 
BUILD_DIR="./build"
BUILD_TOOL="Ninja"
BUILD_ARGS="-D CMAKE_BUILD_TYPE=Debug"

cmake -G $BUILD_TOOL -B $BUILD_DIR $BUILD_ARGS
cmake --build $BUILD_DIR

