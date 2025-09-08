cmake_minimum_required(VERSION 3.10)
project(LearnOpenCV)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    main.cpp
    src/LearnOpenCV.cpp
)

add_executable(LearnOpenCV ${SOURCES})
target_link_libraries(LearnOpenCV ${OpenCV_LIBS})	