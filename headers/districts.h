#ifndef districts_HH
#define districts_HH

#include <string>
#include <vector>
#include "Citizens.h"
#include "Alarmed.h"
#include "Ignorant.h"
#include "Zombie.h"

using namespace std;

class District
{ /// District Class
private:
    string name;

public:
    District(string districtName);
    Alarmed alarm;
    Ignorant ignorant;
    Zombie zombie;
    void set_aware();
    void set_ignorant();
    void set_zombie();
    int countainer_count(); // overloaded function
    float rate_of_growth(); // overloaded function
};

#endif