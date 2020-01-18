//Initialize the closed list
// Created by mor on 17.1.2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H

#include <unordered_set>
#include "TempSearcher.h"
#include "MatrixSolution.h"
#include "math.h"

template<typename T>
class AStar : public TempSearcher<T> {

    Solution *backTrace(State<T> *v) {
        vector<State<T> *> *path = new vector<State<T> *>();
        while (v != nullptr) {
            path->push_back(v);
            v = v->cameFrom;
        }
        MatrixSolution *sol = new MatrixSolution(path);
        return sol;
    }

    Solution *search(Searchable<T> *searchable) {
        vector<State<string> *> backTraceAnsVec;

        State *initialState = searchable->getInitialState();
        initialState->setHeuristicCost(searchable->h(*initialState));
        this->minHeap.insert(initialState); // Insert initial state

        // Iterations
        while (!this->minHeap.isEmpty()) {

            State *n = this->minHeap.extractMin(); // extract min

            this->closed.insert(n); // insert to closed set

            this->numberOfNodesEvaluated++; // update the number of iterations

            // If we finished (we are in the goal state)
            if (*n == *(searchable->getGoalState())) {

                backTraceAnsVec = this->reversePath(this->backTrace(searchable, n)); // get the path

                //this->restartSearcher(); // restart the Best-First-Search class

                return backTraceAnsVec; // return the path (Solution)
            }

            vector<State *> successors = searchable->getAllPossibleStates(n); // successors vector

            // Iterate over all the adj's of n
            for (State *s : successors) {
                // If we did  not visit at this element yet
                if (!this->isExistClosed(s) && !this->isExistOpen(s)) {

                    s->setCameFrom(n); // initial the father
                    s->setCost(s->getCost() + n->getCost()); // initial the  cost
                    s->setHeuristicCost(s->getCost() + searchable->h(*s)); // initial the heuristic cost
                    this->minHeap.insert(s); // insert to the min_heap
                }

                    // Else
                else {
                    // Check if we can do the 'Relax' process
                    if (s->getCost() > s->getCost() + n->getCost()) {

                        this->minHeap.remove(s); // remove s from the min_heap
                        s->setCameFrom(n); // set the new father of s
                        s->setCost(s->getCost() + n->getCost()); // set the new cost of s (after 'relax')
                        s->setHeuristicCost(s->getCost() + searchable->h(*s)); // initial the heuristic cost
                        this->minHeap.insert(s); // insert the updated s to the min_heap

                    }
                }
            }
        }

        return 0;
    }


    double calculateHValue(State<T> *s, Searchable<T> *searchable) {
//        return ((double) sqrt((s->rowPos - searchable->getEnd().first) * (s->rowPos - searchable->getEnd().first)
//                              + (s->colPos - searchable->getEnd().second) * (s->colPos - searchable->getEnd().second)));
        double xDiff = abs(s->rowPos - searchable->getEnd().first);
        double yDiff = abs(s->colPos - searchable->getEnd().second);

        return abs(xDiff + yDiff);
    }

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H
