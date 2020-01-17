//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H

#include "State.h"
#include <list>

using namespace std;

template<typename T>
class Searchable {
public:
    State<T> *getInitialState() = 0;

    bool isGoalState(State<T> s) = 0;

    list<State<T> *> *getAllPossibleStates(State<T> s) = 0;
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
