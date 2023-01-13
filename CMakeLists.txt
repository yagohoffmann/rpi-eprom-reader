cmake_minimum_required(VERSION 2.4)

project(rpi-eprom-reader)

set (CMAKE_CXX_FLAGS "-march=armv6 -mfloat-abi=hard -mfpu=vfp")

add_executable(rpi-eprom-reader src/main.cpp)
