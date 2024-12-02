
#include "District.h"


void Zombie::Interact(string person) {
    // if the current person is an Ignorant Person or Alarmed Person, turn them into a zombie
    if (typeid(person) == typeid(Alarmed)) {
        zombie.list.push_back(person); // adding the person to the zombie list
        alarm.list.pop_back(person); // removing them from the previous container
    } else if(typeid(person) == typeid(Ignorant)) {
        zombie.list.push_back(person); // adding the person to the zombie list
        ignorant.list.pop_back(person); // removing them from the previous container
    }
}