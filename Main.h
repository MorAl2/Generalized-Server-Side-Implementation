#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H

#include <iostream>
#include "Solver.h"
#include "CacheManager.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "State.h"
#include <queue>
#include "SearcherAbstract.h"
#include "MatrixProblem.h"
#include "MatrixSolution.h"
#include "MyClientHandler.h"
#include "SolverTester.h"
#include "SearcherStack.h"
#include "DFSearch.h"
#include "AStar.h"
#include "ObjectAdapter.h"
#include "BestFS.h"
#include "TestAlgo.h"
#include "BFS.h"
#include "MyParallelServer.h"

using namespace server_side;
using namespace std;
namespace server_side {
namespace boot {
class Main {
 public:
  int main(int argc, char *argv[]) {
    int port;
    if (argc > 1) {
      port = atoi(argv[1]);
    }
    else {
      port = 5600;
    }
    Searcher<std::string> *k = new AStar<std::string>();
    Solver<MatrixProblem *, MatrixSolution *> *reverse = new ObjectAdapter<MatrixProblem *, MatrixSolution *>(k);
    CacheManager<MatrixProblem *, MatrixSolution *> *cache = new FileCacheManager<MatrixProblem *, MatrixSolution *>(5);
    ClientHandler *handler = new MyClientHandler(reverse, cache);
    server_side::Server *serial = new MyParallelServer();
    thread *th2ptr = serial->open(port, handler);
    th2ptr->join();
  }
};
}
}

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
