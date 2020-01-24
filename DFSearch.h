#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_DFSEARCH_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_DFSEARCH_H

#include <iostream>
#include "SearcherStack.h"
#include "Searcher.h"
#include "MatrixSolution.h"

using namespace std;
template<typename T>
// class for the dfs algorithm
class DFSearch : public SearcherStack<T> {
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
    // adding the first vertex to stack.
    this->pushToStack(searchable->getInitialState());
    // going over the stack.
    while (!this->empty()) {
      // poping from the stack.
      State<T> *v = this->popFromStack();
      this->nodesCount++;
      // if its the goal state returning the path.
      if (searchable->isGoalState(v)) {
        return backTrace(v);
      }
      // if it was discovred.
      if (v->isDisc == false) {
        v->isDisc = true;
        vector<State<T> *> *adjList = searchable->getAllPossibleStates(v);
        // going on all the states.
        for (State<T> *const &ver: (*adjList)) {
          if (ver->isDisc == false) {
            ver->setCameFrom(v);
            this->pushToStack(ver);
          }
        }
      }
    }
    // if the goal wasnt found, returning empty path.
    return new MatrixSolution(new vector<State<T> *>());
  }

  /**
   * getter of the number of the field nodesCount
   * @return the value of the field nodesCount
   */
  int getNumberOfNodesEvaluated() override {
    this->nodesCount;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_DFSEARCH_H
