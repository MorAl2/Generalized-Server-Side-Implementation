cmake_minimum_required(VERSION 3.15)
project(Generalized-Server-Side-Implementation)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Generalized-Server-Side-Implementation Server.h ClientHandler.h MySerialServer.h MySerialServer.cpp MyTestClientHandler.h MyTestClientHandler.cpp Solver.h Solver.cpp CacheManager.h FileCacheManager.h FileCacheManager.cpp StringReverser.h StringReverser.cpp test.cpp Main.h State.h State.cpp Searchable.h Searcher.h Solution.h Solution.cpp SearcherAbstract.h SearcherAbstract.cpp MyPriorityQueue.h MyPriorityQueue.cpp)