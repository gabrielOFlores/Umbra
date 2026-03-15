#!/bin/bash

#compile for unix based systems

echo -x # for debug
echo -e

compiler="clang++"
compiler_flags="-std=c++20"

project_name="Umbra"
project_sources="../engine/windowing/source/*.cpp ../engine/core/source/*.cpp ../sandbox/*.cpp"
project_includers="-I../engine/windowing/include/ -I../engine/core/include/"
libraries="-lglfw -lvulkan"

mkdir -p ../bin

echo "Compiling $project_name..."
$compiler $compiler_flags $project_sources -o../bin/$project_name $project_includers $libraries