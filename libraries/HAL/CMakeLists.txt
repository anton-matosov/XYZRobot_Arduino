cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME HAL)
project(${PROJECT_NAME})


file(GLOB_RECURSE ALL_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE ALL_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# So far HAL is header only, so building static lib will fail
#add_library(${PROJECT_NAME} STATIC ${ALL_HDRS} ${ALL_SRCS})
#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
