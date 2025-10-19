#!/bin/bash
#
# MIT License
#
# Copyright (c) 2017-2025 Christian (graetz23@gmail.com)
# 
BUILD_DIR="./build"
BUILD_TOOL="Ninja"

cmake -G $BUILD_TOOL -B $BUILD_DIR
cmake --build $BUILD_DIR

