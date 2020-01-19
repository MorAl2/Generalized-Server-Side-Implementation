#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H

#include "State.h"
#include "Searcher.h"
#include <queue>
#include <vector>
#include "CompareState.h"

template<typename T>
class TempSearcher : public Searcher<T> {

    priority_queue<State<T> *, vector<State<T> *>, CompareState<T>> *openList;

    int evaluatedNodes;
    vector<State<T> *> *vectorOpenList;
public:
    TempSearcher() {
        openList = new priority_queue<State<T> *, vector<State<T> *>, CompareState<T>>();
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

    priority_queue<State<T> *, vector<State<T> *>, CompareState<T>> *getOpenList() {
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
        }
        return false;
    }

    void remove(State<string>* element) {

        std::vector<State<string>*> vec;

        while (!openList->empty()) {

            State<string>* currentElem = openList->top();
            bool areEquals = (element == currentElem);

            if (areEquals == false) {
                vec.push_back(currentElem);
            }
            openList->pop();
        }

        for (int i = 0; i < vec.size(); i++) {
            openList->push(vec[i]);
        }
    }

protected:
    virtual State<T> *popOpenList() {
        evaluatedNodes++;
        State<T> *temp = openList->top();
        int i = 0;
        for (State<T> *const &ver: (*vectorOpenList)) {
            if(ver==temp){
                vectorOpenList->erase(vectorOpenList->begin()+i);
            }
            i++;
        }
        openList->pop();
        return temp;
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H
