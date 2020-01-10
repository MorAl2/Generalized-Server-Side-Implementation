#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H

#include "ClientHandler.h"

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

}






//    namespace boot {
//        class Main {
//        public:
//            int main(int argc, char *argv[]) {
//                printf("%s\n",argv[0]);
//            }
//        };
//    }



#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
