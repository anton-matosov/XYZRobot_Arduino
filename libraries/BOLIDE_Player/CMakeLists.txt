cmake_minimum_required(VERSION 3.5)
project(BOLIDE_Player)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BOLIDE_PLAYER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCE_FILES *.h *.cpp)
add_library(BOLIDE_Player ${SOURCE_FILES})

