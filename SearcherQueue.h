//
// Created by noy on 19/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERQUEUE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERQUEUE_H
#include "Searcher.h"
#include "queue"
#include "State.h"

using namespace std;

template<typename T>
class SearcherQueue : public Searcher<T> {
    queue<State<T> * > _queue;
public:
    void pushToQueue(State<T> *state) {
        _queue.push(state);
    }

    State<T> *topOfQueue() {
        return _queue.front();
    }

    State<T> *popFromQueue() {
        auto temp = _queue.front();
        _queue.pop();
        return temp;
    }

    bool empty() {
        return (_queue.empty());
    }

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERQUEUE_H
