//
// Created by noy on 08/01/2020.
//
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYSERIALSERVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "Server.h"
using namespace server_side;
class MySerialServer : public Server {
public:
    /**
     * open server and wait for clients
     * @param port port number to listen
     * @param c object of ClientHandler - define type of conversation
     */
    virtual void open(int port, ClientHandler* c);

    /**
     * close server
     */
    virtual void stop();
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYSERIALSERVER_H
