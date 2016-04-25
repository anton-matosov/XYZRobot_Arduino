cmake_minimum_required(VERSION 3.5)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME XYZRobor_Arduino)
project(${PROJECT_NAME})


add_subdirectory(MainProjects/Bolide)
