#include "Graph.h"
Graph::Graph(District _one, District _two, District _three, District _four, District _five){
  one = _one;
  two = _two;
  three = _three;
  four = _four;
  five = _five;
}
void Graph::Populate_districts(ifstream &Citizens, float pp_one, float pp_two, float pp_three, float pp_four, float pp_five){
  //initialize vector and string variables used to take name from txt file
  vector<string> hey;
  string name;
  string last;
  
  //use district citzens method to determine amount of people per district
  district_citizens(pp_one);
  district_citizens(pp_two);
  //push bounds of dsitricts by adding after using district_citizens method
  pp_two += pp_one;
  district_citizens(pp_three);
  pp_three += pp_two;
  district_citizens(pp_four);
  pp_four += pp_three;
  district_citizens(pp_five);
  pp_five += pp_four;
  //while loop that transfers txt file data to strings
  while (Citizens >> name >> last)
  {
    //concatanate into one string
    name = name + " " + last;
    //pushback name into vector
    hey.push_back(name);
  }
  //for loop that places each citizen in respective districts
  for(int i =0; i<2000;i++){
    //if statements that determine where to place citizens based on the boundary previously set (the pp's)
    if(i<=pp_one){
      //if statements that sets citizen zombie and aware using vector elements, else set into first district as ignorant
      if(i == 0){
      one.set_zombie(hey[i]);
    }
    else if(i == 1){
      two.set_aware(hey[i]);
    }else if (i>1){
      one.set_ignorant(hey[i]);
    }
    }
    //within pp_two boundary, set citizen as ignorant
    else if( i>pp_one&&i<=pp_two){
     
      two.set_ignorant(hey[i]);
    }
    //within pp_three boundary, set citizen as ignorant
    else if(i>pp_two&&i<=pp_three){
      three.set_ignorant(hey[i]);
    }
    //within pp_four boundary, set citizen as ignorant
    else if(i >pp_three&&i<=pp_four){
      four.set_ignorant(hey[i]);
    }
    //within pp_five boundary, set citizen as ignorant
    else if(i>pp_four&&i<=pp_five){
      five.set_ignorant(hey[i]);
    }
  }
    
  }


void Graph::Migrate(){ // Controls movement between the different districts
    Scramble(one, 1);
    Scramble(two, 2);
    Scramble(three, 3);
    Scramble(four, 4);
    Scramble(five, 5);
}




void Graph::Scramble(District cur, int curInt){
  for(int i = 0; i < cur.alarm.list.size(); i++){
    if (isMoved("High")){
        District target = moveOver(curInt);
        target.alarm.list.push_back(cur.alarm.list[i]);
        cur.alarm.list.erase(cur.alarm.list.begin() + i-1);
    }
  }
  for(int i = 0; i < cur.ignorant.list.size(); i++){
    if (isMoved("Low")){
        District target = moveOver(curInt);
        target.ignorant.list.push_back(cur.ignorant.list[i]);
        cur.ignorant.list.erase(cur.ignorant.list.begin() + i-1);
    }
  }
  for(int i = 0; i < cur.zombie.list.size(); i++){
    if (isMoved("Low")){
        District target = moveOver(curInt);
        target.zombie.list.push_back(cur.zombie.list[i]);
        cur.alarm.list.erase(cur.zombie.list.begin() + i-1);
    }
  }
}

District Graph::moveOver(int currentDistrict){   //untested
  bool found = false;
  while (!found){
    int index  = rand()%5;
    if (District_graph[currentDistrict-1][index]){
      found = true;
      return District_map[index];
    };
  };
}


bool Graph::isMoved(string probability){
  if (probability == "high"){
    if (rand() % 100 < 75) return true;
      else return false;
  } else {
    if (rand() % 100 < 50) return true;
      else return false;
  }
}


void Graph::Quarantine(){
}

float Graph::district_citizens(float &s){
  s = (s / 100) * 2000;
  return s;
}