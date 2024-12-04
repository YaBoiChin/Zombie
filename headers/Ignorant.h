#ifndef _IGNORANT_H_
#define _IGNORANT_H_
#include "Citizens.h"
template <typename T>
class Ignorant : public Citizen
{
public:
    Ignorant() : Citizen(){};
    Ignorant(std::string name) : Citizen(name) {};
    virtual void Interact(Citizen<T> person); // It we will decide depending on coolness factor DANCE
    virtual string 
};

#endif