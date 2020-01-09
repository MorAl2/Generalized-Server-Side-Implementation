//
// Created by noy on 08/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <typename Problem,typename Solution>
// Class template with two parameters
class MyTestClientHandler:public ClientHandler {
Solver<Problem,Solution> solver;
CacheManager<Problem,Solution> cm;
public:
    /**
 * get two streams for communication between server and client
 * @param is stream for input data from client
 * @param os stream of output to server's answer
 */
    void handleClient(istream &is, ostream &os);

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H
