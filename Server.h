#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"

namespace server_side {
    class Server {
    protected:
        bool threadCondition = false;
    public:
        /**
         * open server and wait for clients
         * @param port - port # to listen on.
         * @param c -  object of ClientHandler - define type of Stream.
         */
        virtual void open(int port, ClientHandler *c) = 0;

        /**
         * stop Listening for Clients.
         */
        virtual void stop() = 0;
    };


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

}










#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
