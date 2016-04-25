cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Bolide)
project(${PROJECT_NAME})

set(ARDUINO_DEFAULT_BOARD XYZrobot1280)
set(ARDUINO_DEFAULT_PORT /dev/cu.usbserial-A104D3XB)

message("ArduinoSDK: ${ARDUINO_SDK_VERSION}")

set(XYZ_SHARED_PROJECTS ${CMAKE_CURRENT_SOURCE_DIR}/../../XYZSharedProjects)

link_directories(${XYZ_SHARED_PROJECTS}/libraries)

register_hardware_platform("${XYZ_SHARED_PROJECTS}/hardware/XYZrobot/Current/XYZrobot")

generate_arduino_firmware(${CMAKE_PROJECT_NAME}
        SKETCH Bolide.ino
)