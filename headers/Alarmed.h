#ifndef _ALARMED_H_
#define _ALARMED_H_
#include <string>
#include "Citizens.h"
template <typename T>
class Alarmed : public Citizen{
public:
  Alarmed() : Citizen(){};
  Alarmed(std::string name) : Citizen(name) {}
  virtual string report_self(Citizen<T> person) {

    string state;
    
    if (typeid(person) == typeid(Alarmed)) {
      state = "Alarmed";
    } 

    return state;
  }
};

#endif