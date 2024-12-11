#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include "Citizens.h"
#include <string>


class Zombie: public Citizen{
    public:
        Zombie() : Citizen(){};

        virtual void speak(const Citizen& other) const {
        std::cout << "\"Brains... I will eat you, human!!!!!! " << std::endl;
        }
};

#endif