#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H

#include <iostream>
#include "Solver.h"
#include "CacheManager.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

using namespace server_side;

using namespace std;

namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            try {
                int port = atoi(argv[1]);
                Solver<string, string> *reverse = new StringReverser();
                CacheManager<string, string> *cache = new FileCacheManager(5);
                ClientHandler *handler = new MyTestClientHandler(reverse, cache);
                server_side::Server *serial = new MySerialServer();
                serial->open(port, handler);
                cout << "Main Done.." << endl;
                while (serial->getCondition()) {

                }
            }
            catch (const char *e) {
                cout << e << endl;
            }
        }
    };
}


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
