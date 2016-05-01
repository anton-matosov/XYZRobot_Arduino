cmake_minimum_required(VERSION 3.5)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME XYZRobor_Arduino)
project(${PROJECT_NAME})


set(XYZ_PROJECTS_ROOT ${CMAKE_SOURCE_DIR})
set(XYZ_SHARED_PROJECTS ${XYZ_PROJECTS_ROOT}/XYZSharedProjects)

set(ARDUINO_DEFAULT_BOARD XYZrobot1280)
set(ARDUINO_DEFAULT_PORT /dev/cu.usbserial-A104D3XB)

message("ArduinoSDK: ${ARDUINO_SDK_VERSION}")

link_directories(${XYZ_PROJECTS_ROOT}/libraries)
link_directories(${XYZ_SHARED_PROJECTS}/libraries)

register_hardware_platform("${XYZ_SHARED_PROJECTS}/hardware/XYZrobot/Current/XYZrobot")


add_subdirectory(MainProjects/Bolide)
add_subdirectory(MainProjects/RobotEditor)
add_subdirectory(MainProjects/ServoIdSetting)
