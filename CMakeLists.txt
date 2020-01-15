cmake_minimum_required(VERSION 3.15)
project(GoogleTestRepo)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)

set(SOURCE_FILES main.cpp Controller/Controller.cpp Controller/Controller.h Controller/ControllerIfU.h Controller/MockController.h)

add_executable(GoogleTestRepo ${SOURCE_FILES})

target_link_libraries(GoogleTestRepo gtest gtest_main gmock)
