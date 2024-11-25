#ifndef _ALARMED_H_
#define _ALARMED_H_
#include "Citizens.h"

class Alarmed: public Citizen{
    public:
      Alarmed(string name):Citizen(name){};
        void virtual Interact();
};

#endif