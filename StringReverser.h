//
// Created by noy on 09/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STRINGREVERSER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STRINGREVERSER_H
using namespace std;

#include <string>
#include "Solver.h"

class StringReverser : public Solver<string,string>{
public:
    string solve(string p);
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STRINGREVERSER_H
