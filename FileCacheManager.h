//
// Created by noy on 09/01/2020.
//

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H

#include "CacheManager.h"
template <typename Problem,typename Solution>
// Class template with two parameters
class FileCacheManager:public CacheManager<Problem,Solution>{
public:
    /**
     * check if has solution in cache for problem p
     * @param p problem for check
     * @return true - if has solution , otherwise - return false
     */
    bool hasSolution(Problem p);
    /**
     * return solution for problem p
     * @param p problem
     * @return solution for problem p
     */
    Solution getSolution(Problem p);
    /**
     * get problem p and solution s , save them in cache
     * @param p problem
     * @param s solution for problem p
     */
    void saveSolution(Problem p,Solution s);

};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
