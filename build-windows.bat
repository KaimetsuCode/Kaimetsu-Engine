@echo off

if not exist build mkdir build
rem generate CMake Files
cmake -O . -B./build -DCMAKE_BUILD_TYPE=Debug -DBuild_SHARED_LIBS=ON

rem copy assets & .dll files to output dir
robocopy "./Assets" "./build/bin/Debug/Assets" /E
robocopy "./Windows/bin" "./build/bin/Debug" /E

rem compile project
cd build && cmake --build .
echo Compilation Finished!