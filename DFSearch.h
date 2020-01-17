#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_DFSEARCH_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_DFSEARCH_H

#include <iostream>
#include "SearcherStack.h"
#include "Searcher.h"
#include "MatrixSolution.h"

using namespace std;

template<typename T>
class DFSearch : public SearcherStack<T> {
public:
    Solution* backTrace(State<T> *v) {
        vector<State<T> *> *path = new vector<State<T> *>();

        while (v != nullptr) {
            path->push_back(v);
            v = v->cameFrom;
        }
        MatrixSolution* sol= new MatrixSolution(path);
        return sol;
    }

    Solution* search(Searchable<T> *searchable) override {
        this->pushToStack(searchable->getInitialState());
        while (!this->empty()) {
            State<T> *v = this->popFromStack();
            this->nodesCount++;
            if (searchable->isGoalState(v)) {
                return backTrace(v);
            }
            if (v->isDisc == false) {
                v->isDisc = true;
                vector<State<T> *> *adjList = searchable->getAllPossibleStates(v);
                for (State<T> *const &ver: (*adjList)) {
                    if (ver->isDisc == false) {
                        ver->setCameFrom(v);
                        this->pushToStack(ver);
                    }
                }
            }
        }
        return nullptr;
    }

    int getNumberOfNodesEvaluated() override {
        this->nodesCount;
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_DFSEARCH_H
