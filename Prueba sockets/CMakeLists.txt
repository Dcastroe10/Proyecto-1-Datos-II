cmake_minimum_required(VERSION 3.21)
project(Prueba_sockets)

set(CMAKE_CXX_STANDARD 14)

add_executable(Prueba_sockets Client.cpp Client.h Server.cpp Server.h)
