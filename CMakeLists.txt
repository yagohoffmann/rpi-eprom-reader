cmake_minimum_required(VERSION 2.4)

project(rpi-eprom-reader)

set (CMAKE_CXX_FLAGS "-march=armv6 -mfloat-abi=hard -mfpu=vfp")

include_directories(rpi-eprom-reader PUBLIC /usr/include)

add_executable(rpi-eprom-reader src/main.cpp)

target_include_directories(rpi-eprom-reader PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(rpi-eprom-reader /home/yago.araujo/home-projects/libs/libgpiod.so)