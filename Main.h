#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H

#include <iostream>
#include "Solver.h"
#include "CacheManager.h"
#include "Server.h"

using namespace std;
namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            int port = atoi(argv[1]);
            Solver<string,string>* reverse = new StringReverser();
            CacheManager<string,string>* cache = new FileCacheManager(5);
            server_side::Server* serial = new MySerialServer();
        }
    };
}


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
