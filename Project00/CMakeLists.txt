cmake_minimum_required(VERSION 3.10)

project(project00)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(project00 main.cpp)

target_link_libraries(project00 ${OpenCV_LIBS})