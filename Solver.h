//
// Created by noy on 08/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SOLVER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SOLVER_H

template <typename Problem,typename Solution>
// Class template with two parameters
class Solver {
public:
    /**
     * get type parameter <problem> and return type parameter <solution>
     * @param p type parameter problem
     * @return solution of problem
     */
    virtual Solution solve(Problem p)=0;
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_SOLVER_H
