#!/usr/bin/env bash

destination=$PWD
cmakedir=cmake-install

if [[ $# -eq 1 ]]; then
    destination=$1
fi

mkdir -p $cmakedir && cd $cmakedir && cmake install .. && cmake --build . --config Debug --target INSTALL && mv lib $destination && cd .. && rm -rf $cmakedir