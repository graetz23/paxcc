#!/bin/bash
#
# MIT License
#
# Copyright (c) 2017-2025 Christian (graetz23@gmail.com)
# 
BUILD_DIR="./build"
BUILD_TOOL="Ninja"
BUILD_ARGS="--target clean"

cmake --build $BUILD_DIR $BUILD_ARGS

