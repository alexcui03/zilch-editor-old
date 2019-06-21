@echo off

set CMAKE_PREFIX_PATH=D:\Program\Qt\5.12.1\msvc2017_64\lib\cmake

mkdir build
cd build
mkdir win64
cd win64
cmake ../.. -G "Visual Studio 16 2019" -A x64
