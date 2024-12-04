#include "Districts.h"


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