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

  State<string> *getInitialState() {
    return matrix.at(startX)->at(startY);
  }
  bool isGoalState(State<string> s) {
    if (s.rowPos == endX && s.colPos == endY) {
      return true;
    }
    return false;
  }
  vector<State<string> *> *getAllPossibleStates(State<string> s) {
    int row = s.rowPos;
    int col = s.colPos;
    int size = matrix.size() - 1;
    vector<State<string> *> *adjList = new vector<State<string> *>();

    if (row != size && col != size && row != 0 && col != 0) {
      adjList->push_back(matrix.at(row)->at(col - 1));
      adjList->push_back(matrix.at(row)->at(col + 1));
      adjList->push_back(matrix.at(row - 1)->at(col));
      adjList->push_back(matrix.at(row + 1)->at(col));
    } else if (row == size) {
      if (col == 0) {
        adjList->push_back(matrix.at(row)->at(col + 1));
        adjList->push_back(matrix.at(row - 1)->at(col));
      }
      else if (col == size) {
        adjList->push_back(matrix.at(row)->at(col - 1));
        adjList->push_back(matrix.at(row - 1)->at(col));
      } else {
        adjList->push_back(matrix.at(row)->at(col - 1));
        adjList->push_back(matrix.at(row)->at(col + 1));
        adjList->push_back(matrix.at(row - 1)->at(col));
      }

    } else if (col == size) {
      if (row == 0) {
        adjList->push_back(matrix.at(row)->at(col - 1));
        adjList->push_back(matrix.at(row + 1)->at(col));
      } else {
        adjList->push_back(matrix.at(row)->at(col - 1));
        adjList->push_back(matrix.at(row + 1)->at(col));
        adjList->push_back(matrix.at(row - 1)->at(col));
      }

    } else if (row == 0) {
      if (col == 0) {
        adjList->push_back(matrix.at(row)->at(col + 1));
        adjList->push_back(matrix.at(row + 1)->at(col));
      } else {
        adjList->push_back(matrix.at(row + 1)->at(col));
        adjList->push_back(matrix.at(row)->at(col + 1));
        adjList->push_back(matrix.at(row)->at(col - 1));
      }

    } else if (col == 0) {
      adjList->push_back(matrix.at(row + 1)->at(col));
      adjList->push_back(matrix.at(row)->at(col + 1));
      adjList->push_back(matrix.at(row - 1)->at(col));
    }
    return adjList;
  }

};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
