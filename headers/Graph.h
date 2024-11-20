#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <map>
#include <string>
#include <fstream>
#include "Districts.h"

using namespace std;
class Graph{
  private:
  bool District_graph[5][5];
  public:
  map<int,District> District_map;
  void Populate_districts(ifstream& Citizens);
};

#endif