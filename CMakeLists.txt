cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (hippo)


add_library(HippoUtility
HippoUtility/Console.cpp
HippoUtility/File.cpp
)

add_library(SubStringSouffle
SubStringSouffle/SubStringUtils.cpp
SubStringSouffle/STRTraverse.cpp
SubStringSouffle/SubStringSouffle.cpp
)


add_executable(hippo main.cpp)


 TARGET_LINK_LIBRARIES( hippo
 SubStringSouffle
 HippoUtility
 pthread
)