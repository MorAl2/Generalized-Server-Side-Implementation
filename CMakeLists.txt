cmake_minimum_required(VERSION 3.15)
project(Generalized-Server-Side-Implementation)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Generalized-Server-Side-Implementation Server.h  Server.cpp ClientHandler.h ClientHandler.cpp MySerialServer.h MySerialServer.cpp MyTestClientHandler.h MyTestClientHandler.cpp)