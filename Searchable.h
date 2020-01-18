//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H

#include "State.h"
#include <list>
#include <vector>

using namespace std;

template<typename T>
class Searchable {
    pair<int, int> src;
    pair<int, int> target;
public:
    virtual State<T> *getInitialState() {}

    virtual bool isGoalState(State<T> *s) {}

    virtual vector<State<T> *> *getAllPossibleStates(State<T> *s) {}

    virtual pair<int, int> getStart(){}

    virtual pair<int, int> getEnd(){}
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
