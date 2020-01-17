#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERSTACK_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERSTACK_H


#include "State.h"
#include "Searcher.h"
#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class SearcherStack : public Searcher<T> {
    stack<State<T> *> _stack;

public:
    void pushToStack(State<T> *state) {
        _stack.push(state);
    }

    State<T> *topOfStack() {
        return _stack.top();
    }

    State<T> *popFromStack() {
        auto temp = _stack.top();
        _stack.pop();
        return temp;
    }

    bool empty() {
        return (_stack.empty());
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERSTACK_H
