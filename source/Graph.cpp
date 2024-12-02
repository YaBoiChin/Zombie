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
  //set int variable that will be used for incrementation, which will help with while loop control
  int choice = -1;
  //use district citzens method to determine amount of people per district
  district_citizens(pp_one);
  district_citizens(pp_two);
  //set 
  pp_two += pp_one;
  district_citizens(pp_three);
  pp_three += pp_two;
  district_citizens(pp_four);
  pp_four += pp_three;
  district_citizens(pp_five);
  pp_five += pp_four;

  while (Citizens >> name >> last)
  {
    name = name + " " + last;
    hey.push_back(name);
    if(choice == -1){
one.set_zombie();
choice = -2;
    }
    if (choice == -2){
      two.set_zombie();
      choice = 0;
    }
    if(choice>=0 &&choice <= pp_one){
      one.set_ignorant();
    }
    
    else if( choice>pp_one&&choice<=pp_two){
      two.set_ignorant();
    }
    else if(choice>pp_two&&choice<=pp_three){
      three.set_ignorant();
    }
    else if(choice >pp_three&&choice<=pp_four){
      four.set_ignorant();
    }
    else if(choice>pp_four&&choice<=pp_five){
      five.set_ignorant();
    }

    choice++;
  }
}

void Graph::Migrate(){ // Controls movement between the different districts
// District ONE
  for(int i = 0; i < one.alarm.list.size(); i++){
    if (isMoved()){
        District target = moveOver(1);
        target.alarm.list.push_back(one.alarm.list[i]);
    }
  }
  for(int i = 0; i < one.ignorant.list.size(); i++){
    
  }
  for(int i = 0; i < one.zombie.list.size(); i++){
    
  }


// District TWO
  for(int i = 0; i < two.alarm.list.size(); i++){
    
  }
  for(int i = 0; i < two.ignorant.list.size(); i++){
    
  }
  for(int i = 0; i < two.zombie.list.size(); i++){
    
  }





// District THREE
  for(int i = 0; i < three.alarm.list.size(); i++){
    
  }
  for(int i = 0; i < three.ignorant.list.size(); i++){
    
  }
  for(int i = 0; i < three.zombie.list.size(); i++){
    
  }




// District FOUR
  for(int i = 0; i < four.alarm.list.size(); i++){
    
  }
  for(int i = 0; i < four.alarm.list.size(); i++){
    
  }
  for(int i = 0; i < four.alarm.list.size(); i++){
    
  }







// District FIVE
  for(int i = 0; i < five.alarm.list.size(); i++){
    
  }
  for(int i = 0; i < five.alarm.list.size(); i++){
    
  }
  for(int i = 0; i < five.alarm.list.size(); i++){
    
  }

}

District Graph::moveOver(int currentDistrict){   //untested
  bool found = false;
  while (!found){
    int index  = rand()%5;
    if (District_graph[currentDistrict-1][index]){
      found = true;
      return District_map.at(index);
    };
  };
}
void Graph::Quarantine(){
}

float Graph::district_citizens(float &s){
  s = (s / 100) * 2000;
  return s;
}