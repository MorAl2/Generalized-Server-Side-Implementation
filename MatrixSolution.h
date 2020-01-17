#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_

#include <iostream>
#include <vector>
#include "Solution.h"
#include "State.h"

using namespace std;

class MatrixSolution : public Solution {
    vector<State<string> *> *path;
    string state;

public:
    MatrixSolution(string data) {
        state = data;
    }

    MatrixSolution(vector<State<string> *> *pat) {
        this->path = pat;
    }

    string getSolution() override {
        string instruction = "";


        for (int i = path->size() - 1; i > 0; i--) {
            int cuurRow = path->at(i)->rowPos;
            int cuurCol = path->at(i)->colPos;

            int nextRow = path->at(i - 1)->rowPos;
            int nextCol = path->at(i - 1)->colPos;

            if (nextRow > cuurRow) {
                instruction += "Down ";
            }
            if (nextRow < cuurRow) {
                instruction += "Up ";
            }
            if (nextCol > cuurCol) {
                instruction += "Right ";
            }
            if (nextCol < cuurCol) {
                instruction += "Left ";
            }
        }
        return instruction;

    }

    string

    to_string() {
        return state;
    }

};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXSOLUTION_H_
