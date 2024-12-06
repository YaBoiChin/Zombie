#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include "Citizens.h"
#include <string>
template <typename T>

    class Zombie: public Citizen{
        public:
            Zombie() : Citizen(){};
            Zombie(std::string name): Citizen(name){} 
            virtual string report_self(Citizen<T> person) {

            string state;
            
             if(typeid(person) == typeid(Zombie)) {
            state = "Zombie";
             }

            return state;
  }
};

#endif