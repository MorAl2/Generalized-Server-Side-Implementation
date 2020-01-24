#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H

#include <unordered_set>
#include "TempSearcher.h"
#include "MatrixSolution.h"
#include "math.h"

template<typename T>
// class for the AStar Algorithm.
class AStar : public TempSearcher<T, TempComprator<T>> {
  /**
   * given the goal veterx reached returns the shortest Path.
   * @param v - the goal vertex.
   * @return Solution with the shortest Path.
   */
  Solution *backTrace(State<T> *v) {
    // vector to hold the path vertex.
    vector<State<T> *> *path = new vector<State<T> *>();
    // go to to the p(v) until reaching the start vertex.
    while (v != nullptr) {
      // adding the vertex to the vector.
      path->push_back(v);
      // getting the p(v).
      v = v->cameFrom;
    }
    // Creating a Solution class.
    MatrixSolution *sol = new MatrixSolution(path);
    // returning the solution.
    return sol;
  }
  /**
   * Activating the search algorithm on the problem.
   * @param searchable - the object to search on.
   * @return Solution with the shortest Path.
   */
  Solution *search(Searchable<T> *searchable) {
    this->erase();
    // getting the start vertex setting its h and adding to openList.
    State<T> *init = searchable->getInitialState();
    init->h = calculateHValue(init, searchable);
    this->addToOpenList(init);
    // the closed list.
    unordered_set<State<T> *> *closed = new unordered_set<State<T> *>;
    while (this->openListSize() != 0) {
      // poping the head verex which is the smallest h from the priorty queue.
      State<T> *checkedVertex = this->popOpenList();
      // adding to the evaluted nodes.
      this->nodesCount++;
      // adding it to the closed list.
      closed->insert(checkedVertex);
      // if we reached the goal, stopping and getting the Solution.
      if (searchable->isGoalState(checkedVertex)) {
        return backTrace(checkedVertex);
      }
      // geting all the possible states.
      vector<State<T> *> *possibleStates = searchable->getAllPossibleStates(checkedVertex);
      // going for each of the states.
      for (State<T> *states : *possibleStates) {
        // if it isnt being or was checked.
        if (closed->find(states) == closed->end() && !this->openContains(states)) {
          // setting the p(v).
          states->setCameFrom(checkedVertex);
          // updating the feilds.
          states->sumState = (states->sumState + checkedVertex->sumState);
          states->h = states->sumState + calculateHValue(states, searchable);
          // adding it to the open list to be checked.
          this->addToOpenList(states);
        } else {
          // checking if there is a better path.
          if (states->sumState > states->sumState + checkedVertex->sumState) {
            // updating the vertex and removing and adding to the open list.
            this->remove(states);
            closed->erase(closed->find(states));
            states->setCameFrom(checkedVertex);
            states->sumState = (states->sumState + checkedVertex->sumState);
            states->h = states->sumState + calculateHValue(states, searchable);
            this->addToOpenList(states);
          }
        }
      }
    }
    // if error occurd and the goal wasn't reached returning empty path.
    return new MatrixSolution(new vector<State<T> *>());

  }
  /**
   *   calculating the h of the vertex.
   */
  double calculateHValue(State<T> *s, Searchable<T> *searchable) {
    double xDiff = abs(s->rowPos - searchable->getEnd().first);
    double yDiff = abs(s->colPos - searchable->getEnd().second);
    return abs(xDiff + yDiff);
  }

  Searcher<T>* getClone(){
    return new AStar();
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_ASTAR_H
