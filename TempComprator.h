#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPCOMPRATOR_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPCOMPRATOR_H

#include "State.h"

template<typename T>
struct TempComprator {
  bool operator()(State<T> *const &p1, State<T> *const &p2) {
    // return "true" if "p1" is ordered
    // before "p2", by the huristic function.
    return p1->h > p2->h;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPCOMPRATOR_H
