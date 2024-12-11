#ifndef _ALARMED_H_
#define _ALARMED_H_

#include "Citizens.h"

class Alarmed : public Citizen
{
public:
    Alarmed() : Citizen() {}

    void speak(const Citizen& other) const{ // the ability to warn ignorant people
        std::cout << " says: \"Watch out, you ignorant person! Danger is near! , that or you're a zombie about to eat me!" << std::endl;
    }
};

#endif
