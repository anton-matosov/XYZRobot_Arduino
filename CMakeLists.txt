cmake_minimum_required(VERSION 3.5)

set(CMAKE_TOOLCHAIN_FILE $ENV{CONAN_CMAKE_TOOLCHAIN_FILE})

set(PROJECT_NAME XYZRobor_Arduino)
project(${PROJECT_NAME})

add_definitions("-std=c++11")

if(NOT EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  message(
    FATA_ERROR
      "The file conanbuildinfo.cmake doesn't exist.\nRun 'conan install' first..."
    )
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Register board and libraries
link_directories(${CMAKE_SOURCE_DIR}/libraries)

# Setup global config for board, port and serial
set(ARDUINO_DEFAULT_BOARD XYZrobot1280)
set(ARDUINO_DEFAULT_PORT /dev/cu.usbserial-A104D3XB)
set(ARDUINO_DEFAULT_SERIAL screen @SERIAL_PORT@ 115200)


set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${SOURCE_DIR}/Bolide)
add_subdirectory(${SOURCE_DIR}/RobotEditor)
add_subdirectory(${SOURCE_DIR}/ServoIdSetting)
