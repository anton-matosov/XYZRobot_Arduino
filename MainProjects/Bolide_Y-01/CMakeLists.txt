cmake_minimum_required(VERSION 3.5)
project(Bolide_Y_01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB HEADER_FILES *.h)
set(SOURCE_FILES Bolide_Y-01.ino main.cpp)

add_executable(Bolide_Y_01 ${SOURCE_FILES} ${HEADER_FILES})

