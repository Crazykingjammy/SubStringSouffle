cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (hippo)
add_executable(hippo SubStringSouffle/SubStringSouffle.cpp main.cpp)
