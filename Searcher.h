//
// Created by noy on 12/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHER_H

#include "Solution.h"
#include "Searchable.h"
template <typename T>
class Searcher {
public:
    Solution search(Searchable<T> searchable){}
    int getNumberOfNodesEvaluated(){}
};
#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHER_H
