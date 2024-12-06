#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include "Citizens.h"
#include "Districts.h"
#include <string>
template <typename T>

    class Zombie: public Citizen{
        public:
            Zombie() : Citizen(){};
            Zombie(std::string name): Citizen(name){} 
            virtual void Interact(Citizen<T> person) {
                // if the current person is an Ignorant Person or Alarmed Person, turn them into a zombie
                if (typeid(person) == typeid(Alarmed)) {
                    zombie.list.push_back(person); // adding the person to the zombie list
                    alarm.list.pop_back(person); // removing them from the previous container
                } else if(typeid(person) == typeid(Ignorant)) {
                    this->list.push_back(person); // adding the person to the zombie list
                    ignorant.list.pop_back(person); // removing them from the previous container
                }
            }
            virtual string report_self();
};

#endif