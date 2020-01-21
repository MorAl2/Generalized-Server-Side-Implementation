//
// Created by noy on 15/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TESTALGO_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_TESTALGO_H

#include "Searchable.h"
#include "State.h"
#include "string"
#include "vector"
template<typename T>
class TestAlgo : public Searchable<T> {
  vector<vector<State<string> *> *> matrix;
  State<string> *s1;
  State<string> *s25;
 public:
  TestAlgo<T>() {
    s1 = new State<string>("s1");
    State<string> *s2 = new State<string>("s2");
    State<string> *s3 = new State<string>("s3");
    State<string> *s4 = new State<string>("s4");
    State<string> *s5 = new State<string>("s5");
    vector<State<string> *> *mat1 = new vector<State<string> *>;
    mat1->push_back(s1);
    mat1->push_back(s2);
    mat1->push_back(s3);
    mat1->push_back(s4);
    mat1->push_back(s5);
    s1->setPosition(0, 0);
    s2->setPosition(0, 1);
    s3->setPosition(0, 2);
    s4->setPosition(0, 3);
    s5->setPosition(0, 4);
    s1->setCost(1);
    s2->setCost(1);
    s3->setCost(-1);
    s4->setCost(1);
    s5->setCost(1);
    State<string> *s6 = new State<string>("s6");
    State<string> *s7 = new State<string>("s7");
    State<string> *s8 = new State<string>("s8");
    State<string> *s9 = new State<string>("s9");
    State<string> *s10 = new State<string>("s10");
    vector<State<string> *> *mat2 = new vector<State<string> *>;
    mat2->push_back(s6);
    mat2->push_back(s7);
    mat2->push_back(s8);
    mat2->push_back(s9);
    mat2->push_back(s10);
    s6->setPosition(1, 0);
    s7->setPosition(1, 1);
    s8->setPosition(1, 2);
    s9->setPosition(1, 3);
    s10->setPosition(1, 4);
    s6->setCost(-1);
    s7->setCost(1);
    s8->setCost(1);
    s9->setCost(1);
    s10->setCost(1);
    State<string> *s11 = new State<string>("s11");
    State<string> *s12 = new State<string>("s12");
    State<string> *s13 = new State<string>("s13");
    State<string> *s14 = new State<string>("s14");
    State<string> *s15 = new State<string>("s15");
    vector<State<string> *> *mat3 = new vector<State<string> *>;
    mat3->push_back(s11);
    mat3->push_back(s12);
    mat3->push_back(s13);
    mat3->push_back(s14);
    mat3->push_back(s15);
    s11->setPosition(2, 0);
    s12->setPosition(2, 1);
    s13->setPosition(2, 2);
    s14->setPosition(2, 3);
    s15->setPosition(2, 4);
    s11->setCost(1);
    s12->setCost(1);
    s13->setCost(1);
    s14->setCost(-1);
    s15->setCost(1);
    State<string> *s16 = new State<string>("s16");
    State<string> *s17 = new State<string>("s17");
    State<string> *s18 = new State<string>("s18");
    State<string> *s19 = new State<string>("s19");
    State<string> *s20 = new State<string>("s20");
    vector<State<string> *> *mat4 = new vector<State<string> *>;
    mat4->push_back(s16);
    mat4->push_back(s17);
    mat4->push_back(s18);
    mat4->push_back(s19);
    mat4->push_back(s20);
    s16->setPosition(3, 0);
    s17->setPosition(3, 1);
    s18->setPosition(3, 2);
    s19->setPosition(3, 3);
    s20->setPosition(3, 4);
    s16->setCost(1);
    s17->setCost(1);
    s18->setCost(1);
    s19->setCost(1);
    s20->setCost(-1);
    State<string> *s21 = new State<string>("s21");
    State<string> *s22 = new State<string>("s22");
    State<string> *s23 = new State<string>("s23");
    State<string> *s24 = new State<string>("s24");
    s25 = new State<string>("s25");
    vector<State<string> *> *mat5 = new vector<State<string> *>;
    mat5->push_back(s21);
    mat5->push_back(s22);
    mat5->push_back(s23);
    mat5->push_back(s24);
    mat5->push_back(s25);
    s21->setPosition(4, 0);
    s22->setPosition(4, 1);
    s23->setPosition(4, 2);
    s24->setPosition(4, 3);
    s25->setPosition(4, 4);
    s21->setCost(1);
    s22->setCost(1);
    s23->setCost(-1);
    s24->setCost(1);
    s25->setCost(1);
    matrix.push_back(mat1);
    matrix.push_back(mat2);
    matrix.push_back(mat3);
    matrix.push_back(mat4);
    matrix.push_back(mat5);
  }
  State<string> *getInitialState() {
    return s1;
  }

  bool isGoalState(State<string> *s) {
    if (s == s25) {
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