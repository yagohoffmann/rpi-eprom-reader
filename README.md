# rpi-eprom-reader
Generic EPROM reader with raspberry pi

## Cross compile
For cross compile with CMake one option is export CXX enviroment variable with 
g++ path.
Ex: export CXX=/path/to/compiler/cross-pi/bin/arm-linux-gnueabihf-g++

Cross compiler downloaded from 
https://sourceforge.net/projects/raspberry-pi-cross-compilers/files/

Another option is when you're using Buildroot system, you can use a file usually
loacated in output/host/share named "toolchain.cmake" (use grep to find it).
This file configures the paths and flags for all the cross tools used to build
and debug the target application.
To use it enter the output folder of this project and run:

`cmake ../ --toolchain=/PATH/buildroot/output/host/share/buildroot/toolchainfile.cmake`

After that you can run make inside output folder and it should build the project
with no problems. To be sure the changes were applied by the toolchain file,
you can check the paths for C and C++ compilers inside file CMakeCache.txt.

## Libs for linking
Since I'm using a custom firmware from Buildroot, all .so and include files
can be found inside output folder. As described above we can start CMake project
passing the path to a toolchain.cmake file, wich will automatically configure
all the paths of the libs and the headers.