//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H

#include "Searcher.h"
#include <queue>
#include "CompareState.h"
#include <vector>
template <typename T>
class SearcherAbstract : public Searcher<T>{

priority_queue<State<T>, vector<State<T>>,CompareState<T>> *openList;
int evaluatedNodes;
vector<State<T>> *vectorOpenList;
public:
    SearcherAbstract(){
        openList = new (priority_queue<State<T>, vector<State<T>>,CompareState<T>>);
        evaluatedNodes=0;
        vectorOpenList = new vector<State<T>>;
    }
    virtual int openListSize(){
        return openList->size();
    }
    virtual int getNumberOfNodesEvaluated(){
        return this->evaluatedNodes;
    }
    virtual Solution* search(Searchable<T> searchable)  {};
    priority_queue<State<T>, vector<State<T>> ,CompareState<T>> *getOpenList(){
        return this->openList;
    }
    void addToOpenList(State<T> s){
        openList->push(s);
        vectorOpenList->push_back(s);
    }
    bool openContains(State<T> s) {
        for (State<T> x: vectorOpenList) {
            if (x == s) {
                return true;
            }
            return false;
        }
    }
protected:
    virtual State<T> popOpenList(){
        evaluatedNodes++;
        State<T> temp = openList->top();
        openList->pop();
        return temp;
    }
};



#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H
