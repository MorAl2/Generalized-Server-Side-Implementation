#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYSERIALSERVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "Server.h"
#include <thread>

using namespace std;
using namespace server_side;
// running the server with serial input handle.
class MySerialServer : public server_side::Server {
    int port;
    ClientHandler* handler;

public:
    /**
     * open server and wait for clients
     * @param port port number to listen
     * @param c object of ClientHandler - define type of conversation
     */
    thread* open(int port, ClientHandler *c);

    /**
     * stop Listening for Clients.
     */
    virtual void stop();

    void run();
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYSERIALSERVER_H
