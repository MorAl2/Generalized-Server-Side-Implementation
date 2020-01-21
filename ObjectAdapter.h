#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_OBJECTADAPTER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_OBJECTADAPTER_H

#include <string>
#include "Solver.h"
#include "Searchable.h"
#include "MatrixSolution.h"
#include "MatrixProblem.h"
#include "Searcher.h"
#include <iostream>

using namespace std;
template<typename Problem, typename Sol>
// adapting the searcher to the solver.
class ObjectAdapter : public Solver<MatrixProblem *, MatrixSolution *> {
  // the searchable objects.s
  Searcher<string> *searchab;
 public:
  /** CTOR.
   *
   * @param searc the searchable object.
   */
  ObjectAdapter(Searcher<string> *searc) {
    this->searchab = searc;
  }
  /** solving the problem with the searcher.
   *
   * @param p the problem.
   * @return The Solution.
   */
  MatrixSolution *solve(Problem p) override {
    this->searchab->search(p);
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_OBJECTADAPTER_H
