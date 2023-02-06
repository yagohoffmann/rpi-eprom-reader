cmake_minimum_required(VERSION 2.4)

project(rpi-eprom-reader)

set (CMAKE_CXX_FLAGS "-march=armv6 -mfloat-abi=hard -mfpu=vfp")

add_executable(rpi-eprom-reader src/main.cpp)

target_sources(rpi-eprom-reader PRIVATE src/cli.cpp src/hal_gpio.cpp)

target_include_directories(rpi-eprom-reader PRIVATE
                           ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# Export CROSS_C_LIBS var with the path to your cross compiled libs
target_link_libraries(rpi-eprom-reader $ENV{CROSS_C_LIBS}/libgpiod.so)