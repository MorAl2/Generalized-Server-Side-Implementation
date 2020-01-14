//
// Created by mor on 14.1.2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
#include <iostream>
#include <vector>
using namespace std;


class MatrixProblem {
  string state;
  vector<vector<int>*> matrix;

 public:
  MatrixProblem(string data){
    state = data;
  }
  string to_string(){
    return state;
  }
  void addline(vector<int> *mat){
    matrix.push_back(mat);
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
