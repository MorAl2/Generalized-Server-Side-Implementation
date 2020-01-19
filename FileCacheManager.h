
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>

using namespace std;
template<typename Problem, typename Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
  unsigned int maxCacheSize;
  list<string> rluList;
  unordered_map<string, pair<string, list<string>::iterator>> ramCache;

 public:
  FileCacheManager(int size) {
    maxCacheSize = size;
  }

  bool isSolutionExists(Problem p) {
    ifstream file;
    string fileName = p->to_string() + "." + typeid(this).name();
    std::size_t h1 = std::hash<std::string>{}(fileName);
    file.open(to_string(h1), ios::in);
    if (file) {
      return true;
    }
    return false;
  }

  string getSolution(Problem p) {
    ifstream file;
    string fileName = p->to_string() + "." + typeid(this).name();
    std::size_t h1 = std::hash<std::string>{}(fileName);
    file.open(to_string(h1), ios::in);
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

  void addSolution(Problem p, Solution s) {
    // writing to the Disk.
    string fileName = p->to_string() + "." + typeid(this).name();
    std::size_t h1 = std::hash<std::string>{}(fileName);
    ofstream file;
    cout << h1;
    file.open(to_string(h1));
    if (!file) {
      throw "an error";
    }
    file.write(s->to_string().c_str(), s->to_string().length());
    file.close();
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
