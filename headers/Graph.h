#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <map>
#include <stack>
#include <string>
#include <fstream>
#include "District.h"

class Graph
{
private:
  bool District_graph[5][5] = {{false, true, false, false, true},
                               {true, false, false, true, true /*yeah boi*/},
                               {false, false, false, true, false},
                               {false, true, true, false, false},
                               {true, true /*yeah boi*/, false, false, false}};

public:
  District one, two, three, four, five;
  std::map<int, District *> District_map;
  Graph(District &_one, District &_two, District &_three, District &_four, District &_five);
  void Populate_districts(std::ifstream &Citizens, float pp_one, float pp_two, float pp_three, float pp_four, float pp_five);
  void Migrate();
  void Scramble(District &current, int curInt);
  int moveOver(int currentDistrict);
  bool isMoved(std::string Probability);
  void Quarantine(int District);
  float district_citizens(float &s);
  void processList(std::vector<std::string>& srcList, const std::string& probability, int curInt,std::vector<int>& targets, std::vector<std::string>& temp);
};

#endif
