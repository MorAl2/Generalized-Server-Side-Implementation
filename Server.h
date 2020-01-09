//
// Created by noy on 08/01/2020.
//
// TODO - add namespace
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
#include "ClientHandler.h"
#include "MySerialServer.h"
namespace server_side {
    class Server {
    public:
        /**
         * open server and wait for clients
         * @param port port number to listen
         * @param c object of ClientHandler - define type of conversation
         */
        virtual void open(int port, ClientHandler* c) = 0;

        /**
         * close server
         */
        virtual void stop() = 0;
    };
    namespace boot {
        class Main {
        public:
            int main(int argc, char *argv[]) {
                printf("%s\n",argv[0]);
                //Server s = new MySerialServer();

            }
        };
    }
}


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
