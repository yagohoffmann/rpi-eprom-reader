# rpi-eprom-reader
Generic EPROM reader with raspberry pi

## Cross compile
For cross compile with CMake export CXX enviroment variable with g++ path.
Ex: export CXX=/path/to/compiler/cross-pi-gcc-10.3.0-0/bin/arm-linux-gnueabihf-g++

Cross compiler downloaded from https://sourceforge.net/projects/raspberry-pi-cross-compilers/files/

## Libs for linking
At the moment I installed the libgpiod on raspberry pi and copied the libgpiod.so file to my host
machine. Before building I export the CROSS_C_LIBS var with the path where I put the .so file.