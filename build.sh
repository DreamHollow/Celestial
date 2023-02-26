#!/bin/sh

echo "Building Celestial Game Engine..."
cmake -S . -B build
cd build
make
echo "Compilation complete."
