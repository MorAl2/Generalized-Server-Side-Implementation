//
// Created by noy on 08/01/2020.
//
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CLIENTHANDLER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CLIENTHANDLER_H
#include <iostream>

using namespace std;

class ClientHandler {
public:
    /**
     * get two streams for communication between server and client
     * @param is stream for input data from client
     * @param os stream of output to server's answer
     */
    virtual void handleClient(istream &is , ostream &os) = 0;
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CLIENTHANDLER_H
