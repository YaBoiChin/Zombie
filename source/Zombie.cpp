
#include "Zombie.h"


template <typename T>
void Interact(Citizen<T> person) {
    // if the current person is an Ignorant Person or Alarmed Person, turn them into a zombie
    if (typeid(person) == typeid(Alarmed)) {
        this->list.push_back(person); // adding the person to the zombie list
        alarm.pop_back(person); // removing them from the previous container
    } else if(typeid(person) == typeid(Ignorant)) {
        this->list.push_back(person); // adding the person to the zombie list
        ignorant.list.pop_back(person); // removing them from the previous container
    }
}