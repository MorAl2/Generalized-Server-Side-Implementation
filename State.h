//
// Created by noy on 11/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H

template<typename T>
struct State {
  T state;
  double cost;
  State<T> *cameFrom;
  double sumState;
 public:
  State(T state) {
    this->state = state;
  }
  State(T stat, double Cost) {
    this->state = stat;
    this->cost = Cost;
  }
  T getState() {
    return this->state;
  }
  void setCameFrom(State<T> s) {
    this->cameFrom = s;
  }
  void setSumState(State<T> s) {
    this->cameFrom = s;
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
  bool operator==(State<T> other) {
    if ((this->state == other.getState())) {
      return true;
    }
    return false;
  }

};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_STATE_H
