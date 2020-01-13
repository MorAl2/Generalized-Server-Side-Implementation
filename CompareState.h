//
// Created by noy on 13/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_COMPARESTATE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_COMPARESTATE_H

#include "State.h"
template <typename T>
struct CompareState {
    bool operator()(State<T> const &p1, State<T> const &p2) {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.getCost() < p2.getCost();
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_COMPARESTATE_H
