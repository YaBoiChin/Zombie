#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include "Citizens.h"
#include <string>

    class Zombie: public Citizen{
        public:
            Zombie(std::string name): Citizen(name){} 
            virtual void  Interact();
};

#endif