cmake_minimum_required(VERSION 3.15)
project(Generalized-Server-Side-Implementation)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Generalized-Server-Side-Implementation Server.h ClientHandler.h MySerialServer.h MySerialServer.cpp MyTestClientHandler.h MyTestClientHandler.cpp Solver.h Solver.cpp CacheManager.h FileCacheManager.h FileCacheManager.cpp StringReverser.h StringReverser.cpp test.cpp Main.h State.h State.cpp Searchable.h Searcher.h Solution.h Solution.cpp SearcherAbstract.h SearcherAbstract.cpp CompareState.h CompareState.cpp BestFS.h BestFS.cpp MyClientHandler.cpp MyClientHandler.h MatrixProblem.cpp MatrixProblem.h MatrixSolution.cpp MatrixSolution.h SolverTester.cpp SolverTester.h DFSearch.cpp DFSearch.h SearcherStack.h AStar.cpp AStar.h RegAStar.cpp RegAStar.h TempSearcher.cpp TempSearcher.h TempComprator.cpp TempComprator.h TestAStar.cpp TestAStar.h ObjectAdapter.cpp ObjectAdapter.h MyParallelServer.cpp MyParallelServer.h)