#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H

#include "State.h"
#include "Searcher.h"
#include <queue>
#include "TempComprator.h"
#include <vector>

template<typename T, typename Comprator>
// getting the wanted comprator for the queue as a param.
class TempSearcher : public Searcher<T> {
  // the open list.
  priority_queue<State<T> *, vector<State<T> *>, Comprator> *openList;
  int evaluatedNodes;
  vector<State<T> *> *vectorOpenList;

 public:
  // CTOR.
  TempSearcher() {
    openList = new priority_queue<State<T> *, vector<State<T> *>, Comprator>();
    evaluatedNodes = 0;
    vectorOpenList = new vector<State<T> *>;
  }
  /**
   *
   * @return the size of the open list.
   */
  virtual int openListSize() {
    return openList->size();
  }

  /**
   * the evaluted nodes.
   * @return the evaluted nodes.
   */
  virtual int getNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
  }

  /**
   * search the problem
   * @param searchable
   * @return The solution.
   */
  virtual Solution *search(Searchable<T> searchable) {};

  /**
   *
   * @return the open list.
   */
  priority_queue<State<T> *, vector<State<T> *>, TempComprator<T>> *getOpenList() {
    return this->openList;
  }

  /**
   * add to the list
   * @param s the state to add.
   */
  void addToOpenList(State<T> *s) {
    openList->push(s);
    vectorOpenList->push_back(s);
  }

  /**
   * if the vertex is in the list.
   * @param s the vertex.
   * @return true or false if exist.
   */
  bool openContains(State<T> *s) {
    for (State<T> *x: (*vectorOpenList)) {
      if (x == s) {
        return true;
      }
    }
    return false;
  }

  /**
   * remove and element from the open list.
   * @param element
   */
  void remove(State<string> *element) {

    std::vector<State<string> *> vec;

    while (!openList->empty()) {

      State<string> *currentElem = openList->top();
      bool areEquals = (element == currentElem);

      if (areEquals == false) {
        vec.push_back(currentElem);
      }
      openList->pop();
    }

    for (int i = 0; i < vec.size(); i++) {
      openList->push(vec[i]);
    }
  }

 protected:
  /**
   * pooping from the open list the head vertex.
   * @return the head vertex.
   */
  virtual State<T> *popOpenList() {
    evaluatedNodes++;
    State<T> *temp = openList->top();
    int i = 0;
    for (State<T> *const &ver: (*vectorOpenList)) {
      if (ver == temp) {
        vectorOpenList->erase(vectorOpenList->begin() + i);
      }
      i++;
    }
    openList->pop();
    return temp;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TEMPSEARCHER_H
