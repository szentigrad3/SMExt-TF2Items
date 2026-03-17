cmake_minimum_required(VERSION 3.10)
project(tf2c_items_ext)
set(CMAKE_CXX_STANDARD 17)

add_library(tf2c_items_ext SHARED extension.cpp)
