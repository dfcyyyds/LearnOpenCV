cmake_minimum_required(VERSION 3.10)
project(CHAPTER2.5)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(chapter2.5 test.cpp)
target_link_libraries(chapter2.5 ${OpenCV_LIBS})