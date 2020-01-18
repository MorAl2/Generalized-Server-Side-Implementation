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
        unordered_set<State<T> *> *closed = new unordered_set<State<T> *>;
        State<T> *init = searchable->getInitialState();
        init->h = calculateHValue(init, searchable);
        this->addToOpenList(init);

        // Iterations
        while (this->openListSize() != 0) {
            State<T> *n = this->popOpenList();
            closed->insert(n);
            this->nodesCount++; // update the number of iterations
            // If we finished (we are in the goal state)
            if (searchable->isGoalState(n)) {
                return backTrace(n); // return the path (Solution)
            }
            vector<State<T> *> *successors = searchable->getAllPossibleStates(n); // successors vector
            // Iterate over all the adj's of n
            for (State<T> *s : *successors) {
                // If we did  not visit at this element yet
                if (closed->find(s) == closed->end() && !this->openContains(s)) {
                    s->setCameFrom(n); // initial the father
                    s->sumState = (s->sumState + n->sumState); // initial the  cost
                    s->h = s->sumState + calculateHValue(s, searchable); // initial the heuristic cost
                    this->addToOpenList(s);
                }
                    // Else
                else {
                    // Check if we can do the 'Relax' process
                    if (s->sumState > s->sumState + n->sumState) {
                        this->remove(s);
                        s->setCameFrom(n); // set the new father of s
                        s->sumState = (s->sumState + n->sumState); // set the new cost of s (after 'relax')
                        s->h = s->sumState + calculateHValue(s, searchable); // initial the heuristic cost
                        this->addToOpenList(s); // insert the updated s to the min_heap
                    }
                }
            }
        }

        return 0;
    }


    double calculateHValue(State<T> *s, Searchable<T> *searchable) {
//       return ((double) sqrt((s->rowPos - searchable->getEnd().first) * (s->rowPos - searchable->getEnd().first)
//                            + (s->colPos - searchable->getEnd().second) * (s->colPos - searchable->getEnd().second)));
        double xDiff = abs(s->rowPos - searchable->getEnd().first);
        double yDiff = abs(s->colPos - searchable->getEnd().second);
        return abs(xDiff + yDiff);
    }

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H
