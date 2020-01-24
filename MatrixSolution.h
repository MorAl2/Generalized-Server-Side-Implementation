#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_

#include <iostream>
#include <vector>
#include "Solution.h"
#include "State.h"

using namespace std;
// holding the soultion for the search.
class MatrixSolution : public Solution {
  vector<State<string> *> *path;
  string state;
 public:
  // CTOR
  MatrixSolution(string data) {
    state = data;
  }
  // CTOR #2
  MatrixSolution(vector<State<string> *> *pat) {
    this->path = pat;
  }

  /**
   *
   * @return the solution as string(up down right left).
   */
  string getSolution() override {
    string instruction = "";
    bool flag = true;

    for (int i = path->size() - 1; i > 0; i--) {
      int cuurRow = path->at(i)->rowPos;
      int cuurCol = path->at(i)->colPos;

      int nextRow = path->at(i - 1)->rowPos;
      int nextCol = path->at(i - 1)->colPos;
      int sumCost;
      if (flag == true) {
        sumCost = path->at(i)->cost;
        flag = false;
      }
      if (nextRow > cuurRow) {
        instruction += "Down ";
        sumCost += path->at(i - 1)->cost;
        instruction += "(";
        instruction += ::to_string(sumCost);
        instruction += ") ,";
      }
      if (nextRow < cuurRow) {
        instruction += "Up ";
        sumCost += path->at(i - 1)->cost;
        instruction += "(";
        instruction += ::to_string(sumCost);
        instruction += ") ,";
      }
      if (nextCol > cuurCol) {
        instruction += "Right ";
        sumCost += path->at(i - 1)->cost;
        instruction += "(";
        instruction += ::to_string(sumCost);
        instruction += ") ,";
      }
      if (nextCol < cuurCol) {
        instruction += "Left ";
        sumCost += path->at(i - 1)->cost;
        instruction += "(";
        instruction += ::to_string(sumCost);
        instruction += ") ,";
      }
    }
    if(instruction == ""){
      instruction = "No Path Was Found.";
      return instruction;
    }
    instruction = instruction.substr(0, instruction.length() - 1);
    state = instruction;
    return instruction;
  }
  /**
   * string of the Solution.
   * @return string of the Solution.
   */
  string to_string() {
    return getSolution();
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
