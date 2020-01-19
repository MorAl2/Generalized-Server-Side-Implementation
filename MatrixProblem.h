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
    pair<int, int> src;
    pair<int, int> target;

public:
    string to_string() {
        return state;
    }

    void addline(vector<State<string> *> *mat) {
        matrix.push_back(mat);
    }

    void setStart(int x, int y) {
        this->src = pair<int, int>(x, y);
    }

    void setEnd(int x, int y) {
        this->target = pair<int, int>(x, y);

    }

    void addToStateString(string x) {
        state.append(x);
    }
    State<string> *getInitialState() {
        return matrix.at(src.first)->at(src.second);
    }

    bool isGoalState(State<string> *s) {
        if (s->rowPos == target.first && s->colPos == target.second) {
            return true;
        }
        return false;
    }

    bool isValidLocation(int row, int col, int size) {
        return (row >= 0) && (row < size) &&
               (col >= 0) && (col < size);
    }


    vector<State<string> *> *getAllPossibleStates(State<string> *s) {
        int row = s->rowPos;
        int col = s->colPos;
        int size = matrix.size();
        vector<State<string> *> *adjList = new vector<State<string> *>();
        if (isValidLocation(row, col - 1, size) && matrix.at(row)->at(col - 1)->cost != -1) {
            adjList->push_back(matrix.at(row)->at(col - 1));
        }
        if (isValidLocation(row, col + 1, size) && matrix.at(row)->at(col + 1)->cost != -1) {
            adjList->push_back(matrix.at(row)->at(col + 1));
        }
        if (isValidLocation(row - 1, col, size) && matrix.at(row - 1)->at(col)->cost != -1) {
            adjList->push_back(matrix.at(row - 1)->at(col));
        }
        if (isValidLocation(row + 1, col, size) && matrix.at(row + 1)->at(col)->cost != -1) {
            adjList->push_back(matrix.at(row + 1)->at(col));
        }
        return adjList;
    }

    virtual pair<int, int> getStart() {
        return this->src;
    }

    virtual pair<int, int> getEnd() {
        return this->target;
    }

};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
