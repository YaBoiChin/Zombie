#ifndef _ALARMED_H_
#define _ALARMED_H_
#include <string>
#include "Citizens.h"
template <typename T>
class Alarmed : public Citizen{
public:
  Alarmed() : Citizen(){};
  Alarmed(std::string name) : Citizen(name) {}
  virtual void Interact(Citizen<T> person);
};

#endif