cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Bolide)
project(${PROJECT_NAME})


#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../XYZSharedProjects/libraries/BOLIDE_Player)

register_hardware_platform("/Users/amatosov.ctr/Develop/XYZRobot/XYZRobot_Arduino/XYZSharedProjects/hardware/XYZrobot/Current/XYZrobot")

#set(BOLIDE_PLAYER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../XYZSharedProjects/libraries/BOLIDE_Player")
#
#file(GLOB BOLIDE_Player_SRCS ${BOLIDE_PLAYER_PATH}/*.cpp)
#file(GLOB BOLIDE_Player_HDRS ${BOLIDE_PLAYER_PATH}/*.h)
#generate_arduino_library(
#        BOLIDE_Player
#        BOARD XYZrobot1280
#)

#message("${BOLIDE_Player_HDRS}")

generate_arduino_firmware(
        ${CMAKE_PROJECT_NAME}
        BOARD XYZrobot1280
#        LIBS BOLIDE_Player
#        HDRS "${BOLIDE_Player_HDRS}"
        SKETCH Bolide.ino
)