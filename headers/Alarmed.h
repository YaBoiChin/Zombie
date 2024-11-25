#ifndef _ALARMED_H_
#define _ALARMED_H_
#include <string>
#include "Citizens.h"

class Alarmed : public Citizen
{
public:
  Alarmed(std::string name) : Citizen(name) {}
  virtual void Interact();
};

#endif