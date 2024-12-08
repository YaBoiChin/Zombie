#include "Graph.h"

Graph::Graph(District& _one, District& _two, District& _three, District& _four, District& _five){
  one = _one;
  two = _two;
  three = _three;
  four = _four;
  five = _five;
  srand(time(NULL));
  District_map[1] = &one;
  District_map[2] = &two;
  District_map[3] = &three;
  District_map[4] = &four;
  District_map[5] = &five;
}

float Graph::district_citizens(float &s){
  s = (s / 100) * 2000;
  return s;
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
    if(i < pp_one){
      //if statements that sets citizen zombie and aware using vector elements, else set into first district as ignorant
      if(i == 0){
      one.alarm.list.push_back(hey[i]);
    } else if(i == 1){
      two.zombie.list.push_back(hey[i]);
    }else if (i>1){
      one.ignorant.list.push_back(hey[i]);
    }
    }
    //within pp_two boundary, set citizen as ignorant
    else if( i>pp_one&&i<pp_two){
      two.ignorant.list.push_back(hey[i]);
    }
    //within pp_three boundary, set citizen as ignorant
    else if(i>pp_two&&i<pp_three){
      three.ignorant.list.push_back(hey[i]);
    }
    //within pp_four boundary, set citizen as ignorant
    else if(i >pp_three&&i<pp_four){
      four.ignorant.list.push_back(hey[i]);
    }
    //within pp_five boundary, set citizen as ignorant
    else if(i>pp_four&&i<pp_five){
      five.ignorant.list.push_back(hey[i]);
    }
  }
    
  }


void Graph::Migrate(){ // Controls movement between the different districts
    Scramble(one, 1);
    // Scramble(two, 2);
    Scramble(three, 3);
    Scramble(four, 4);
    // Scramble(five, 5);
}

void Graph::Scramble(District &cur, int curInt){
    auto it = cur.alarm.list.begin();
    
    vector<string> tempVectA;
    vector<string> tempVectI;
    vector<string> tempVectZ;
    
    while (it != cur.alarm.list.end()) {
        if (isMoved("High")) {
            int target = moveOver(curInt);
            tempVectA.push_back(*it);
            District_map[target]->alarm.list.push_back(tempVectA[tempVectA.size() -1]);
            it = cur.alarm.list.erase(it); 
        } else{
            it++;
        }
    }  

    // for (int x = 0; x < tem)



     it = cur.ignorant.list.begin();
    while(it != cur.ignorant.list.end()) {
      if(isMoved("Low")){
      int target = moveOver(curInt); // returing the district number that it is
       tempVectI.push_back(*it);
       District_map[target]->ignorant.list.push_back(tempVectI[tempVectI.size() -1]);
      it = cur.ignorant.list.erase(it);
    } else{
      it++;
    }
    }

    
  it = cur.zombie.list.begin();
    while(it != cur.zombie.list.end()) {
      if(isMoved("Low")){
      int target = moveOver(curInt); // returning the district number that it is adjacent to
      tempVectZ.push_back(*it);
      District_map[target]->zombie.list.push_back(tempVectZ[tempVectZ.size() -1]);
      it = cur.zombie.list.erase(it);
    } else{
      it++;
    }
  }


cout << cur.name << ": " << District_map[curInt]->ignorant.list.size() << endl;

  
}   



int Graph::moveOver(int currentDistrict){   //untested
  bool found = false;
  int attempt = 0;
  while (!found && attempt < 100){
    int index  = rand()%5;
    attempt++;
    if (District_graph[currentDistrict-1][index]){
      found = true;
      return index;
    }
  }
  return currentDistrict;
}


bool Graph::isMoved(string probability){  //determines whether the individual made the decision to move to a different district
  if (probability == "High"){
    if (rand() % 100 < 75) return true;
      else return false;
  } else {
    if (rand() % 100 < 30) return true;
      else return false;
  }
}


void Graph::Quarantine(int district){
  for (int i = 0; i < 5; i++ ) District_graph[district][i] = false;
}


// void MakeMove(int person) {
//   stack<vector<person*>::iterator> slatedToMove;

// }
