//
// Created by noy on 11/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H

template <typename T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;
public:
    State(T state){
        this->state = state;
    }
    bool operator==(State& s1){
        if(this->state == s1.getState())
            return true;
        return false;
    }
    T getState(){
        return this->state;
    }
    void setCameFrom(State<T> s){
        this->cameFrom = s;
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H
