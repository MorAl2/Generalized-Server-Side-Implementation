#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STRINGREVERSER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STRINGREVERSER_H
using namespace std;

#include <string>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    /**
     * reverse and return the string
     * @param p - the string to reverse.
     * @return - the reveresed string.
     */
    string solve(string p);
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STRINGREVERSER_H
