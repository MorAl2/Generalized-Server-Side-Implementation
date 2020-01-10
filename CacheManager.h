#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CACHEMANAGER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CACHEMANAGER_H

template<typename Problem, typename Solution>
class CacheManager {
public:
    /**
     * check if the solution exists in cache for the problem p
     * @param p - the problem to check
     * @return true - if the solution exists , otherwise - false
     */
    virtual bool isSolutionExists(Problem p) = 0;

    /**
     * return the solution the the problem p
     * @param p - the Problem.
     * @return the solution for The problem p
     */
    virtual Solution getSolution(Problem p) = 0;

    /**
     * rcv problem p and solution s ,and add them to the cache
     * @param p - The problem
     * @param s - The solution for the problem p
     */
    virtual void addSolution(Problem p, Solution s) = 0;
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_CACHEMANAGER_H
