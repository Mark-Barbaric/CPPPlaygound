#! /usr/bin/bash

rm -rf build
mkdir build

echo "Running cmake"
cmake -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -B build -S .

echo "Make build"
make -C build/ -j ${nproc}