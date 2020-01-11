#include <iostream>
#include <sstream>
#include <fstream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        int port = atoi(argv[1]);
        Solver<string, string> *reverse = new StringReverser();
        CacheManager<string, string> *cache = new FileCacheManager(5);
        MyTestClientHandler *s = new MyTestClientHandler(reverse, cache);
        server_side::Server *serial = new MySerialServer();
        serial->open(port, s);
        cout << "Main Done.." << endl;
        while (serial->getCondition()) {

        }
    }
    catch (const char* e){
        cout << e << endl;
    }
}

