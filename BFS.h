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
class BFS : public SearcherQueue<T> {
 public:
  Solution *backTrace(State<T> *v) {
    vector<State<T> *> *path = new vector<State<T> *>();

    while (v != nullptr) {
      path->push_back(v);
      v = v->cameFrom;
    }
    MatrixSolution *sol = new MatrixSolution(path);
    return sol;
  }

  Solution *search(Searchable<T> *searchable) override {
    this->pushToQueue(searchable->getInitialState());
    while (!this->empty()) {
      State<T> *v = this->popFromQueue();
      this->nodesCount++;
      v->setIsDisc();
      if (searchable->isGoalState(v)) {
        return backTrace(v);
      }
      vector<State<T> *> *adjList = searchable->getAllPossibleStates(v);
      for (State<T> *const &ver: (*adjList)) {
        if (ver->getIsDisc() == false) {
          ver->setCameFrom(v);
          ver->setIsDisc();
          this->pushToQueue(ver);
        }
      }
    }
    return nullptr;
  }

  int getNumberOfNodesEvaluated() override {
    this->nodesCount;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_BFS_H
