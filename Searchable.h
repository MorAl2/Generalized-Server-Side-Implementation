#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H

#include "State.h"
#include <list>
#include <vector>

using namespace std;

template<typename T>
// the Searchable Interface.
class Searchable {
  // the start and goal.
  pair<int, int> src;
  pair<int, int> target;
 public:

  /**
 *
 * @return the inital state.
*/
  virtual State<T> *getInitialState() {}

  /**
  * @param s the vertex.
  * @return if its the goal state,
  */
  virtual bool isGoalState(State<T> *s) {}

  /**
  *
  * @return vector with all the possible states.
  */
  virtual vector<State<T> *> *getAllPossibleStates(State<T> *s) {}
/**
 * return the start.
 * @return
 */
  virtual pair<int, int> getStart() {}
/**
 * return the end.
 * @return
 */
  virtual pair<int, int> getEnd() {}
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHABLE_H
