#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H

#include "State.h"
#include "Searcher.h"
#include <queue>
#include "TempComprator.h"
#include <vector>

template<typename T>
class TempSearcher : public Searcher<T> {

    priority_queue<State<T> *, vector<State<T> *>, TempComprator<T>> *openList;

    int evaluatedNodes;
    vector<State<T> *> *vectorOpenList;
public:
    TempSearcher() {
        openList = new priority_queue<State<T> *, vector<State<T> *>, TempComprator<T>>();
        evaluatedNodes = 0;
        vectorOpenList = new vector<State<T> *>;
    }

    virtual int openListSize() {
        return openList->size();
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    virtual Solution *search(Searchable<T> searchable) {};

    priority_queue<State<T> *, vector<State<T> *>, TempComprator<T>> *getOpenList() {
        return this->openList;
    }

    void addToOpenList(State<T> *s) {
        openList->push(s);
        vectorOpenList->push_back(s);
    }

    bool openContains(State<T> *s) {
        for (State<T> *x: (*vectorOpenList)) {
            if (x == s) {
                return true;
            }
            return false;
        }
    }

protected:
    virtual State<T> *popOpenList() {
        evaluatedNodes++;
        State<T> *temp = openList->top();
        openList->pop();
        return temp;
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H
