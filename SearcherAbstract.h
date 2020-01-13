//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H

#include "Searcher.h"
#include <queue>
#include "CompareState.h"
template <typename T>
class SearcherAbstract : public Searcher<T>{

priority_queue<State<T>, vector<State<T>>,CompareState<T>> *openList;
int evaluatedNodes;
public:
    SearcherAbstract(){
        openList = new (priority_queue<State<T>, vector<State<T>>,CompareState<T>>);
        evaluatedNodes=0;
    }
    virtual int openListSize(){
        return openList->size();
    }
    virtual int getNumberOfNodesEvaluated(){
        return this->evaluatedNodes;
    }
    virtual Solution search(Searchable<T> searchable) {}
    priority_queue<State<T>, vector<State<T>>,CompareState<T>> *getOpenList(){
        return this->openList;
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
