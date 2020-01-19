//
// Created by noy on 15/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TESTALGO_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TESTALGO_H

#include "Searchable.h"
#include "State.h"
#include "string"
#include "vector"
template <typename T>
class TestAlgo: public Searchable<T>  {
    vector<vector<State<string> *> *> matrix;
    State<string> *s1;
    State<string> *s9;
public:
    TestAlgo<T>(){
        string x = "a";
        string y = "b";
        string z = "c";
        s1 = new State<string>(x);
        State<string> *s2 = new State<string>(y);
        State<string> *s3 = new State<string>(z);
        vector<State<string> *> *mat1= new vector<State<string> *>;
        mat1->push_back(s1);
        mat1->push_back(s2);
        mat1->push_back(s3);
        s1->setCost(1);
        s2->setCost(1);
        s3->setCost(1);
        s1->setPosition(0,0);
        s2->setPosition(0,1);
        s3->setPosition(0,2);
        string n = "d";
        string o = "e";
        string d = "f";
        State<string> *s4 = new State<string>(n);
        State<string> *s5 = new State<string>(o);
        State<string> *s6 = new State<string>(d);
        vector<State<string> *> *mat2 = new vector<State<string> *>;
        mat2->push_back(s4);
        mat2->push_back(s5);
        mat2->push_back(s6);
        s4->setCost(3);
        s5->setCost(8);
        s6->setCost(100);
        s4->setPosition(1,0);
        s5->setPosition(1,1);
        s6->setPosition(1,2);
        string l = "g";
        string e = "h";
        string v = "i";
        State<string> *s7 = new State<string>(l);
        State<string> *s8 = new State<string>(e);
        s9 = new State<string>(v);
        s7->setCost(12);
        s8->setCost(8);
        s9->setCost(9);
        s7->setPosition(2,0);
        s8->setPosition(2,1);
        s9->setPosition(2,2);
        vector<State<string> *> *mat3 = new vector<State<string> *>;
        mat3->push_back(s7);
        mat3->push_back(s8);
        mat3->push_back(s9);
        matrix.push_back(mat1);
        matrix.push_back(mat2);
        matrix.push_back(mat3);
    }
    State<string> *getInitialState() {
        return s1;
    }

    bool isGoalState(State<string> *s) {
        if (s==s9) {
            return true;
        }
        return false;
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
    bool isValidLocation(int row, int col, int size) {
        return (row >= 0) && (row < size) &&
               (col >= 0) && (col < size);
    }

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TESTALGO_H