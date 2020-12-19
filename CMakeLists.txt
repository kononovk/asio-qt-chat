cmake_minimum_required(VERSION 3.19)
project(server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(server server.cpp)