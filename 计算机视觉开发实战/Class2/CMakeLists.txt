cmake_minimum_required(VERSION 3.10)
project(Class2)
set(CMAKE_CXX_STANDARD 14)

#
find_package(OpenCV REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    main.cpp
    src/quickdemo.cpp
)

add_executable(class2 ${SOURCES})
target_link_libraries(class2 ${OpenCV_LIBS})	

