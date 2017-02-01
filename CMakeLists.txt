cmake_minimum_required(VERSION 3.6)
project(ae_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pred.cpp)
add_executable(ae_project ${SOURCE_FILES})