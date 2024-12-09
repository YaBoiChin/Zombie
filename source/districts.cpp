#include "District.h"


District::District(){
    name = "N/A";
    srand(time(NULL));
}
District::District(string districtName){
    name = districtName;
    srand(time(NULL));
}

int District::countainer_count() { // population of each district
    return alarm.list.size() + ignorant.list.size() + zombie.list.size();
}

float District::rate_of_growth(){ // overloaded function
    return 0;
}

void District::interact_A_Z(float prob) {
    int first, likelihood;

    likelihood =  rand() % 100;

   
    if (likelihood < prob && zombie.list.size() > 0) {
        // find a random person inside the alarmed list
        for (int x = 0; x < alarm.list.size(); x++ ) {
            first = rand() % alarm.list.size();
            }
            // changing the state of the person
            if (!alarm.list.empty()) {
            zombie.list.push_back(alarm.list[first]);
                alarm.list.erase(alarm.list.begin() + first);
            }
        }
}

void District::interact_I_Z(float prob) {
    int first, likelihood;

    likelihood =  rand()%100;

    if ( likelihood < prob && zombie.list.size() > 0) {
        // find a random person inside the alarmed list
        for (int x = 0; x < ignorant.list.size(); x++ ) {
            first = rand() % ignorant.list.size();
            }
            // changing the state of the person
            if (!ignorant.list.empty()) {
            zombie.list.push_back(ignorant.list[first]);
                ignorant.list.erase(ignorant.list.begin() + first);
            }
    }
}

void District::interact_A_I(float prob) {
    int first, likelihood;

    likelihood =  rand() % 100;

    if (likelihood < prob && zombie.list.size() > 0) {
        // find a random person inside the alarmed list
        for (int x = 0; x < ignorant.list.size(); x++ ) {
            first = rand() % ignorant.list.size(); // random index inside ignorant list
            }

            // changing the state of the person
            if (ignorant.list.size() > 0) {
                alarm.list.push_back(ignorant.list[first]);
                ignorant.list.erase(ignorant.list.begin() + first);
            } 
    
    }
}