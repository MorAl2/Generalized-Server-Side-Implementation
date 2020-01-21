#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SOLUTION_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SOLUTION_H

#include <iostream>

using namespace std;
// Interface for a Solution Class.
class Solution {
 public:
  /**
   *
   * @return the solution as a string.
   */
  virtual string getSolution() = 0;
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SOLUTION_H
