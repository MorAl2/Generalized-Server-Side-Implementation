#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_COMPARESTATE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_COMPARESTATE_H

#include "State.h"
template<typename T>
// comprator for the priority queue.
struct CompareState {
  bool operator()(State<T> *const &p1, State<T> *const &p2) {
    // return "true" if "p1" is ordered before "p2"
    return p1->getSumState() > p2->getSumState();
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_COMPARESTATE_H
