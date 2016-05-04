cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Bolide)
project(${PROJECT_NAME})


file(GLOB_RECURSE ALL_CODE_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE ALL_CODE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
generate_arduino_library(ALL_CODE)

generate_arduino_firmware(${PROJECT_NAME}
        SKETCH ${PROJECT_NAME}.ino
        LIBS ALL_CODE
)