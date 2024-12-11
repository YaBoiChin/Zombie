#ifndef _IGNORANT_H_
#define _IGNORANT_H_
#include "Citizens.h"

class Ignorant : public Citizen
{
public:
    Ignorant() : Citizen(){};

    virtual void speak(const Citizen& other) const {
        std::cout << "\"I don't care about what these crazy citizens are saying.\"" << std::endl;
    }
};

#endif