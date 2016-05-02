cmake_minimum_required(VERSION 3.5)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME XYZRobor_Arduino)
project(${PROJECT_NAME})

# Register board and libraries
link_directories(${CMAKE_SOURCE_DIR}/libraries)
register_hardware_platform("${CMAKE_SOURCE_DIR}/hardware/XYZrobot")

# Setup global config for board, port and serial
set(ARDUINO_DEFAULT_BOARD XYZrobot1280)
set(ARDUINO_DEFAULT_PORT /dev/cu.usbserial-A104D3XB)
set(ARDUINO_DEFAULT_SERIAL screen @SERIAL_PORT@ 115200)


set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${SOURCE_DIR}/Bolide)
add_subdirectory(${SOURCE_DIR}/RobotEditor)
add_subdirectory(${SOURCE_DIR}/ServoIdSetting)
