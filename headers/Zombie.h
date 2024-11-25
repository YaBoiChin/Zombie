#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include "Citizens.h"

    class Zombie: public Citizen{
        public:
            Zombie(string name):Citizen(name){};
            void virtual Interact(); // Bite
};

#endif