//
// Created by noy on 09/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CACHEMANAGER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CACHEMANAGER_H

template <typename Problem,typename Solution>
// Class template with two parameters
class CacheManager {
public:
    /**
     * check if has solution in cache for problem p
     * @param p problem for check
     * @return true - if has solution , otherwise - return false
     */
    virtual bool hasSolution(Problem p)=0;
    /**
     * return solution for problem p
     * @param p problem
     * @return solution for problem p
     */
    virtual Solution getSolution(Problem p)=0;
    /**
     * get problem p and solution s , save them in cache
     * @param p problem
     * @param s solution for problem p
     */
    virtual void saveSolution(Problem p,Solution s)=0;

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CACHEMANAGER_H
