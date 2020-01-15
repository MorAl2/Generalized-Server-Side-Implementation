//
// Created by mor on 14.1.2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
#include <iostream>
#include <vector>
#include "State.h"
#include "Searchable.h"
using namespace std;

class MatrixProblem : public Searchable<string> {
  string state;
  vector<vector<State<string> *> *> matrix;
  int startX;
  int startY;
  int endX;
  int endY;

 public:
  string to_string() {
    return state;
  }
  void addline(vector<State<string> *> *mat) {
    matrix.push_back(mat);
  }
  void setStart(int x, int y) {
    startX = x;
    startY = y;
  }
  void setEnd(int x, int y) {
    endX = x;
    endY = y;
  }
  void addToStateString(string x) {
    state.append(x);
  }

  State<string>* getInitialState() {
    return matrix.at(startX)->at(startY);
  }
  bool isGoalState(State<string> s) {
    if(s.rowPos == endX && s.colPos == endY){
      return true;
    }
    return false;
  }
  list<State<string>*> getAllPossibleStates(State<string> s) {

  }

};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
