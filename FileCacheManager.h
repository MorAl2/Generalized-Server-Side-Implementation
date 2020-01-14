
#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
  unsigned int maxCacheSize;
  list<string> rluList;
  unordered_map<string, pair<string, list<string>::iterator>> ramCache;
  unordered_map<string, bool> isSolExist;

 public:
  FileCacheManager(int size) {
    maxCacheSize = size;
  }

  bool isSolutionExists(string p) {
    if (isSolExist.find(p) != isSolExist.end()) {
      return true;
    }
    return false;
  }

  string getSolution(string p) {
    // find the value in the cache
    if (ramCache.find(p) != ramCache.end()) {

      rluList.erase(ramCache[p].second);
      rluList.push_front(p);

      return ramCache[p].first;
    } else {
      ifstream file;
      file.open(p + "." + typeid(this).name(), ios::in);
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

        rluList.push_front(p);
        pair<string, list<string>::iterator> sol = pair<string, list<string>::iterator>(p, rluList.begin());
        ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p, sol));
      } else {

        string lastKey = rluList.back();
        rluList.pop_back();
        ramCache.erase(lastKey);

        // inserting the new one.
        rluList.push_front(p);
        pair<string, list<string>::iterator> sol = pair<string, list<string>::iterator>(p, rluList.begin());
        ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p, sol));
      }
      return sol;
    }
  }

  void addSolution(string p, string s) {
    isSolExist.emplace(p, true);
    // writing to the Disk.
    string fileName = p + "." + typeid(this).name();
    ofstream file;
    file.open(fileName);
    if (!file) {
      throw "an error";
    }
    file.write(s.c_str(), s.length());
    file.close();
    if (rluList.size() < maxCacheSize) {
      rluList.push_front(p);
      pair<string, list<string>::iterator> sol = pair<string, list<string>::iterator>(p, rluList.begin());
      ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p, sol));
    } else if (ramCache.size() >= maxCacheSize) {
      string temp = rluList.back();
      rluList.pop_back();
      ramCache.erase(temp);
      rluList.push_front(p);
      pair<string, list<string>::iterator> sol = pair<string, list<string>::iterator>(p, rluList.begin());
      ramCache.insert(pair<string, pair<string, list<string>::iterator>>(p, sol));;
    }
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_FILECACHEMANAGER_H
