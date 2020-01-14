//
// Created by mor on 14.1.2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
#include <iostream>
using namespace std;

class MatrixSolution {
  string state;

 public:
  MatrixSolution(string data){
    state = data;
  }
  string to_string() {
    return state;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
