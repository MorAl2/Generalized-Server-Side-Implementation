//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYPRIORITYQUEUE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYPRIORITYQUEUE_H
#include <list>
#include "State.h"
using namespace std;
template <typename T>
class MyPriorityQueue {
    list<State<T>> queueState;
public:
    State<T> poll(){
        // TODO - implement poll
    }
    int getCount(){
        return queueState.size();
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYPRIORITYQUEUE_H
