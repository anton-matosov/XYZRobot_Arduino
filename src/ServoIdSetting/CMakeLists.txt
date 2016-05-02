cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME ServoIdSetting)
project(${PROJECT_NAME})

generate_arduino_firmware(${PROJECT_NAME}
        SKETCH ${PROJECT_NAME}.ino
        )