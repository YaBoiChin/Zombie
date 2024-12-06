#include "District.h"

District::District(){
    name = "N/A";
}
    District::District(string districtName){
            name = districtName;
    }

       void District::set_aware(string name){
        alarm.list.push_back(name);
       }
       void District::set_ignorant(string name){
        ignorant.list.push_back(name);
        }
        void District::set_zombie(string name){
            zombie.list.push_back(name);
        }
        int countainer_count() {
            //TODO
        }
        float rate_of_growth(){ // overloaded function
            //TODO
        }
        
        void Interact(Citizen person1, Citizen person2) {
                if (typeid(person1) == typeid(person2)) {
                    // do nothing
                } else {
                    // if the current person is an Ignorant Person or Alarmed Person, turn them into a zombie
                if (typeid(person1) == typeid(Alarmed) && typeid(person2) == typeid(Zombie)) {
                    zombie.list.push_back(person1); 
                    for (int x = 0; x < alarm.list.size(); x++) {
                        if (person1 == alarm.list[x]) {
                            alarm.erase(alarm.list.begin() + (x - 1)); // removing the person at that position
                        }
                    }
                } else if(typeid(person1) == typeid(Ignorant) && typeid(person2) == typeid(Zombie)) {
                    zombie.list.push_back(person1); // adding the person to the zombie list
                    for (int x = 0; x < ignorant.list.size(); x++) {
                        if (person1 == ignorant.list[x]) {
                            ignorant.list.erase(ignorant.begin() + (x - 1)) // removing the person at that position
                        }
                    }
                }

                if (typeid(person2) == typeid(Alarmed) && typeid(person1) == typeid(Zombie)) {
                    zombie.list.push_back(person2); //adding the person to the zombie list
                    for (int x = 0; x < alarm.list.size(); x++) {
                        if (person2 == alarm.list[x]) {
                            alarm.eralarmse(alarm.begin() + (x - 1)) // removing the person at that position
                        }
                    }
                } else if(typeid(person2) == typeid(Ignorant) && typeid(person1) == typeid(Zombie)) {
                    zombie.list.push_back(person2);
                    for (int x = 0; x < ignorant.list.size(); x++) {
                        if (person2 == ignorant[x]) {
                            ignorant.list.erase(ignorant.begin() + (x - 1)) // removing the person at that position
                        }
                    }
                }
                }
            }

