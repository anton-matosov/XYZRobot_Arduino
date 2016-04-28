cmake_minimum_required(VERSION 3.5)

set(XYZ_PROJECTS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(XYZ_SHARED_PROJECTS ${XYZ_PROJECTS_ROOT}/XYZSharedProjects)

set(CMAKE_TOOLCHAIN_FILE ${XYZ_PROJECTS_ROOT}/cmake/ArduinoToolchain.cmake)

set(PROJECT_NAME Bolide)
project(${PROJECT_NAME})

set(ARDUINO_DEFAULT_BOARD XYZrobot1280)
set(ARDUINO_DEFAULT_PORT /dev/cu.usbserial-A104D3XB)

message("ArduinoSDK: ${ARDUINO_SDK_VERSION}")


link_directories(${XYZ_PROJECTS_ROOT}/libraries)
link_directories(${XYZ_SHARED_PROJECTS}/libraries)

register_hardware_platform("${XYZ_SHARED_PROJECTS}/hardware/XYZrobot/Current/XYZrobot")

generate_arduino_library(AnalogJoystick
            HDRS AnalogJoystick.h
            SRCS AnalogJoystick.cpp
        )

generate_arduino_firmware(${CMAKE_PROJECT_NAME}
        SKETCH Bolide.ino
        LIBS AnalogJoystick
)