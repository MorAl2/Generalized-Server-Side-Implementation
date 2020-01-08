//
// Created by noy on 08/01/2020.
//
// TODO - add namespace
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
#include "ClientHandler.h"

class Server {
public:
    /**
     * open server and wait for clients
     * @param port port number to listen
     * @param c object of ClientHandler - define type of conversation
     */
    virtual void open(int port,ClientHandler c) = 0;
    /**
     * close server
     */
    virtual void stop() = 0;
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SERVER_H
