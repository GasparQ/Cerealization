#!/usr/bin/env bash

destination=$PWD
destname=CerealLib

if [[ $# -eq 1 ]]; then
    destination=$1
fi

mkdir -p $destname && cp -r Cerealizable Cerealizer CMakeLists.txt src $destname

if [ $destination != $PWD ]; then
    mv $destname $destination
fi

echo "Project created at: $destination/$destname"