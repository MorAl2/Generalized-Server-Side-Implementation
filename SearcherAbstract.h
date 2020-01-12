//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H

#include "Searcher.h"
#include "MyPriorityQueue.h"
template <typename T>
class SearcherAbstract : public Searcher<T>{
MyPriorityQueue<T> openList;
int evaluatedNodes;
public:
    SearcherAbstract(){
        openList = new MyPriorityQueue<T>;
        evaluatedNodes=0;
    }
    virtual int openListSize(){
        return openList.getCount();
    }
    virtual int getNumberOfNodesEvaluated(){
        return this->evaluatedNodes;
    }
    virtual Solution search(Searchable<T> searchable) = 0;

protected:
    virtual State<T> popOpenList(){
        evaluatedNodes++;
        return openList.poll();
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHERABSTRACT_H
