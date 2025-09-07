   cmake_minimum_required(VERSION 3.28.3)  # 或者你的CMake版本
   project(opencv_example)

   find_package(OpenCV REQUIRED)

   add_executable(opencv_example main.cpp)
   target_link_libraries(opencv_example ${OpenCV_LIBS})
