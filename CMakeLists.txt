cmake_minimum_required(VERSION 3.5)
project(XYZRobot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(./XYZSharedProjects/libraries/BOLIDE_Player)

add_subdirectory(./MainProjects/Bolide_Y-01)
