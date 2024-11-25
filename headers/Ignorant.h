#ifndef _IGNORANT_H_
#define _IGNORANT_H_
#include "Citizens.h"

class Ignorant: public Citizen{
    public:
        Ignorant(string name):Citizen(name){};
        void virtual Interact(); // It we will decide depending on coolness factor DANCE
};

#endif