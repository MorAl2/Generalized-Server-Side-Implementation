//
// Created by noy on 13/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BESTFS_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BESTFS_H

#include "TempSearcher.h"
#include <bits/stdc++.h>
#include "list"
#include "MatrixSolution.h"
#include "CompareState.h"
template <typename T>
class BestFS: public TempSearcher<T> {
// TODO - create back trace through parents
public:
    vector<State<string> *> * backTrace(State<string> *v) {
        vector<State<string> *>*s = new vector<State<string> *>();
        while (v!= NULL){
            s->push_back(v);
            v=v->cameFrom;
        }
        return s;
    }
    Solution* search(Searchable<T> *searchable) {
        searchable->getInitialState()->setCameFrom(NULL);
        priority_queue<State<T> *, vector<State<T> *>, CompareState<T>> * openList = this->getOpenList();
        this->addToOpenList(searchable->getInitialState());
        searchable->getInitialState()->setSumState(searchable->getInitialState()->cost);
        unordered_set <State<T>*> *closed = new unordered_set <State<T>*>;
        while(this->openListSize()>0){
            State<T>* n = this->popOpenList();
            closed->insert(n);
            if(searchable->isGoalState(n)){
                vector<State<string> *>  *backTraceState = backTrace(n);
                vector<State<string> *> *pat;
                MatrixSolution *ms = new MatrixSolution(backTraceState);
                return ms;
            }
            vector<State<T> *> *adjList = searchable->getAllPossibleStates(n);
            for (State<T> *const &s: (*adjList)) {
                if(!(closed->find(s)!=closed->end())&&(!(this->openContains(s)))) {
                    s->setCameFrom(n);
                    s->setSumState((*s).getCost() + n->getSumState());
                    this->addToOpenList(s);
                    // 5.b /
                } else {
                    if((s->getCost()+n->getSumState())<(s->getSumState())){
                        // 5.b.i
                        if(!this->openContains(s)){
                            this->addToOpenList(s);
                            closed->erase(closed->find(s));
                            // 5.b.ii
                        } else {
                            s->setSumState(s->getCost()+n->getSumState());
                            s->setCameFrom(n);
                            this->remove(s);
                            this->addToOpenList(s);
                        }
                    }
                }
            }
        }
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BESTFS_H
