#ifndef _IGNORANT_H_
#define _IGNORANT_H_
#include "Citizens.h"
template <typename T>
class Ignorant : public Citizen
{
public:
    Ignorant() : Citizen(){};
    Ignorant(string name) : Citizen(name) {};
    virtual string report_self(Citizen<T> person) {

    string state;
    
   
   if(typeid(person) == typeid(Ignorant)) {
      state = "Ignorant";
    }

    return state;
  }
};

#endif