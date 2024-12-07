#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <map>
#include <string>
#include <fstream>
#include "District.h"

using namespace std;
class Graph
{
private:
  District  one, two, three, four, five;
  bool District_graph[5][5] = {{false, true, false, false, true}, 
                               {true, false, false, true, true},
                               {false, false, false, true, false},
                               {false, true, true, false, false},
                               {true, true, false, false, false}};

public:
  map<int, District > District_map = {{1, one}, {2, two}, {3, three}, {4, four}, {5, five}};
  Graph(District _one, District _two, District _three, District _four, District _five);
  void Populate_districts(ifstream &Citizens, float pp_one, float pp_two, float pp_three, float pp_four, float pp_five);
  void Migrate();
  void Scramble(District current, int curInt);
  District moveOver(int currentDistrict);
  bool isMoved(string Probability);
  void Quarantine(int District);
  float district_citizens(float &s);
};

#endif