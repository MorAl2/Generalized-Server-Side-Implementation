#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <typename Problem,typename Solution>
class MyTestClientHandler:public ClientHandler {

Solver<Problem,Solution> solver;
CacheManager<Problem,Solution> cm;

public:
    /**
     * handle Input Stream and Output Stream.
     * @param is - input Stream.
     * @param os output Stream.
     */
    void handleClient(int is, int os);

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H
