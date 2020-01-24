#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BFS_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BFS_H
#include "TempSearcher.h"
#include <bits/stdc++.h>
#include "list"
#include "MatrixSolution.h"
#include "CompareState.h"
#include "queue"
#include "SearcherQueue.h"

template<typename T>
// class for the bfs algorithm
class BFS : public SearcherQueue<T> {
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
  Solution *search(Searchable<T> *searchable) override {
    // adding the first vertex to queue.
    this->pushToQueue(searchable->getInitialState());
    // going over the queue.
    while (!this->empty()) {
      State<T> *v = this->popFromQueue();
      this->nodesCount++;
      v->setIsDisc();
      // if its the goal state returning the path.
      if (searchable->isGoalState(v)) {
        return backTrace(v);
      }
      vector<State<T> *> *adjList = searchable->getAllPossibleStates(v);
      // going on all the states.
      for (State<T> *const &ver: (*adjList)) {
        // if it was not discovred.
        if (ver->getIsDisc() == false) {
          ver->setCameFrom(v);
          ver->setIsDisc();
          this->pushToQueue(ver);
        }
      }
    }
    return nullptr;
  }
  /**
  * getter of the number of the field nodesCount
  * @return the value of the field nodesCount
  */
  int getNumberOfNodesEvaluated() override {
    this->nodesCount;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BFS_H
