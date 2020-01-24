#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHER_H

#include "Solution.h"
#include "Searchable.h"

template<typename T>
// the Searcher Interface.
class Searcher {
 protected:
  // the evaluted nodes.
  int nodesCount = 0;
 public:
  /**
   * seaech in the matrix.
   * @param searchable  the matrix.
   * @return the solution.
   */
  virtual Solution *search(Searchable<T> *searchable) {}
  /**
   * the # of evaluted nodes.
   * @return the # of evaluted nodes.
   */
  virtual int getNumberOfNodesEvaluated() {}

  virtual Searcher* getClone(){}
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SEARCHER_H
