//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H

#include "State.h"
#include <list>
using namespace std;
template <typename T>
class Searchable{
    State<T>* getInitialState();
    bool isGoalState(State<T> s);
    list<State<T>*>* getAllPossibleStates(State<T> s);
};
#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
