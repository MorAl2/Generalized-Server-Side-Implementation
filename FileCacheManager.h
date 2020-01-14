
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
  unordered_map<string, bool> isSolExist;

 public:
  FileCacheManager(int size) {
    maxCacheSize = size;
  }

  bool isSolutionExists(Problem p) {
    if (isSolExist.find(p->to_string()) != isSolExist.end()) {
      return true;
    }
    return false;
  }

  string getSolution(Problem p) {
    // find the value in the cache
    if (ramCache.find(p->to_string()) != ramCache.end()) {

      rluList.erase(ramCache[p->to_string()].second);
      rluList.push_front(p->to_string());

      return ramCache[p->to_string()].first;
    } else {
      ifstream file;
      file.open(p->to_string() + "." + typeid(this).name(), ios::in);
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

      if (rluList.size() < maxCacheSize) {
        rluList.push_front(p->to_string());
        pair<string, list<string>::iterator> solPair = pair<string, list<string>::iterator>(p->to_string(), rluList.begin());
        ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p->to_string(), solPair));
      } else {

        string lastKey = rluList.back();
        rluList.pop_back();
        ramCache.erase(lastKey);

        // inserting the new one.
        rluList.push_front(p->to_string());
        pair<string, list<string>::iterator> solPair = pair<string, list<string>::iterator>(p->to_string(), rluList.begin());
        ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p->to_string(), solPair));
      }
      return sol;
    }
  }

  void addSolution(Problem p, Solution s) {
    isSolExist.emplace(p->to_string(), true);
    // writing to the Disk.
    string fileName = p->to_string() + "." + typeid(this).name();
    ofstream file;
    file.open(fileName);
    if (!file) {
      throw "an error";
    }
    file.write(s->to_string().c_str(), s->to_string().length());
    file.close();
    if (rluList.size() < maxCacheSize) {
      rluList.push_front(p->to_string());
      pair<string, list<string>::iterator> solPair = pair<string, list<string>::iterator>(p->to_string(), rluList.begin());
      ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p->to_string(), solPair));
    } else if (ramCache.size() >= maxCacheSize) {
      string temp = rluList.back();
      rluList.pop_back();
      ramCache.erase(temp);
      rluList.push_front(p->to_string());
      pair<string, list<string>::iterator> solPair = pair<string, list<string>::iterator>(p->to_string(), rluList.begin());
      ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p->to_string(), solPair));;
    }
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
