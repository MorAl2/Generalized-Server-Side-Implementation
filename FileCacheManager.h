
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>

using namespace std;
template<typename Problem, typename Solution>
// class for cacheing the solutions.
class FileCacheManager : public CacheManager<Problem, Solution> {
  unsigned int maxCacheSize;
  unordered_map<string, bool> *isExist = new unordered_map<string, bool>();

 public:
  FileCacheManager(int size) {
    maxCacheSize = size;
  }
/**
  * check if the solution exists for the problem p
  * @param p - the problem to check
  * @return true - if the solution exists , otherwise - false
  */
  bool isSolutionExists(Problem p) {
    string fileName = p->to_string() + "." + typeid(this).name();
    std::size_t h1 = std::hash<std::string>{}(fileName);
    if (isExist->find(to_string(h1)) != isExist->end()) {
      return true;
    }

    ifstream file;

    file.open(to_string(h1), ios::in);
    if (file) {
      return true;
    }
    return false;
  }
/**
 * return the solution the the problem p
 * @param p - the Problem.
 * @return the solution for The problem p
 */
  string getSolution(Problem p) {
    ifstream file;
    string fileName = p->to_string() + "." + typeid(this).name();
    std::size_t h1 = std::hash<std::string>{}(fileName);
    file.open(to_string(h1), ios::in);
    isExist->emplace(to_string(h1), true);
    if (!file) {
      cout << "Problem Opening File" << endl;
      throw "an error";
    }
    string temp;
    string sol = "";

    if (!file.good()) {
      file.close();
      cout << "Solution Doesn't Exists On the Disk" << endl;
      throw "an error";
    } else {
      while (getline(file, temp)) {
        sol += temp;
      }
      file.close();
    }
    return sol;
  }
/**
 * rcv problem p and solution s ,and add them to the cache
 * @param p - The problem
 * @param s - The solution for the problem p
 */
  void addSolution(Problem p, Solution s) {
    // writing to the Disk.
    string fileName = p->to_string() + "." + typeid(this).name();
    std::size_t h1 = std::hash<std::string>{}(fileName);
    ofstream file;
    cout << h1;
    file.open(to_string(h1));
    isExist->emplace(to_string(h1), true);
    if (!file) {
      throw "an error";
    }
    file.write(s->to_string().c_str(), s->to_string().length());
    file.close();
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H


