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
// class for the BestFS algorithm
class BestFS: public TempSearcher<T,CompareState<T>> {
public:
    /**
    * given the goal veterx reached returns the shortest Path.
    * @param v - the goal vertex.
    * @return Solution with the shortest Path.
    */
    Solution *backTrace(State<T> *v) {
        vector<State<T> *> *path = new vector<State<T> *>();

        while (v != nullptr) {
            path->push_back(v);
            v = v->cameFrom;
        }
        MatrixSolution *sol = new MatrixSolution(path);
        return sol;
    }
    /**
   * Activating the search algorithm on the problem.
   * @param searchable - the object to search on.
   * @return Solution with the shortest Path.
   */
    Solution* search(Searchable<T> *searchable) {
        // change first vertex came from to NULL
        searchable->getInitialState()->setCameFrom(NULL);
        // add first vertex to open list
        this->addToOpenList(searchable->getInitialState());
        // add cost to sum cost
        searchable->getInitialState()->setSumState(searchable->getInitialState()->cost);
        // create unordered set for vertex was discovred
        unordered_set <State<T>*> *closed = new unordered_set <State<T>*>;
        // go over open list
        while(this->openListSize()>0){
            // poping the head verex which is the smallest cost from the priorty queue.
            State<T>* n = this->popOpenList();
            // insert this element to closed list
            closed->insert(n);
            // adding to the evaluted nodes.
            this->nodesCount++;
            // if we reached the goal, stopping and getting the Solution.
            if(searchable->isGoalState(n)){
                return backTrace(n);
            }
            // geting all the possible states.
            vector<State<T> *> *adjList = searchable->getAllPossibleStates(n);
            // going for each of the states.
            for (State<T> *const &s: (*adjList)) {
                // if neighbor s is not in close and not in open list
                if(!(closed->find(s)!=closed->end())&&(!(this->openContains(s)))) {
                    // updating the feilds.
                    s->setCameFrom(n);
                    s->setSumState((*s).getCost() + n->getSumState());
                    // adding it to the open list to be checked.
                    this->addToOpenList(s);
                } else {
                    // checking if there is a better path.
                    if((s->getCost()+n->getSumState())<(s->getSumState())){
                        // if s is not exist in open list , add to open list and remove from closed
                        if(!this->openContains(s)){
                            this->addToOpenList(s);
                            closed->erase(closed->find(s));
                        } else {
                            // updating the vertex and removing and adding to the open list.
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