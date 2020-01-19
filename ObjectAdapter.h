//
// Created by mor on 18.1.2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_OBJECTADAPTER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_OBJECTADAPTER_H


#include <string>
#include "Solver.h"
#include "Searchable.h"
#include "MatrixSolution.h"

#include "MatrixProblem.h"

#include "Searcher.h"
#include <iostream>
using namespace std;
template<typename Problem, typename Sol>
class ObjectAdapter : public Solver<MatrixProblem*, MatrixSolution*> {
    Searcher<string>* searchab;
public:
    ObjectAdapter(Searcher<string>* searc){
        this->searchab = searc;
    }

    MatrixSolution* solve(Problem p) override {

        this->searchab->search(p);
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_OBJECTADAPTER_H
