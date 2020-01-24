#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CLIENTHANDLER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CLIENTHANDLER_H
#include <iostream>

using namespace std;

class ClientHandler {
public:
    /**
     * handle Input Stream and Output Stream.
     * @param is - input Stream.
     * @param os - output Stream.
     */
    virtual void handleClient(int is , int os) = 0;

    virtual ClientHandler* getClone() {}
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CLIENTHANDLER_H
