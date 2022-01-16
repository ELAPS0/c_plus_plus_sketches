cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(tst)

# add the executable
add_executable(rvo bb_str.cpp rvo.cpp)
