//
// Created by noy on 11/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H

#include <cfloat>

template<typename T>
struct State {
    T state;
    double cost;
    State<T> *cameFrom = nullptr;
    double sumState;
    int rowPos;
    int colPos;
    bool isDisc = false;
    double f = FLT_MAX;
    double h = FLT_MAX;
    double g = FLT_MAX;
public:
    State(T state) {
        this->state = state;
    }

    State(T stat, double Cost) {
        this->state = stat;
        this->cost = Cost;
        this->sumState = cost;
    }

    T getState() {
        return this->state;
    }

    void setCameFrom(State<T> *s) {
        this->cameFrom = s;
    }

    void setPosition(int x, int y) {
        rowPos = x;
        colPos = y;
    }

    void setSumState(double s) {
        this->sumState = s;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    double getCost() const {
        return this->cost;
    }

    State<T> getCameFrom() {
        return this->cameFrom;
    }

    double getSumState() {
        return this->sumState;
    }
    bool getIsDisc(){
        return this->isDisc;
    }
    void setIsDisc(){
        this->isDisc = true;
    }
//    bool operator==(State<T>* other) {
//        if ((this->state == other->getState())) {
//            return true;
//        }
//        return false;
//    }
//
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H
