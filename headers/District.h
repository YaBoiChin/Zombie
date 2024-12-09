#ifndef _DISTRICT_H_
#define _DISTRICT_H_

#include <string>
#include <vector>
#include "Citizens.h"
#include "Alarmed.h"
#include "Ignorant.h"
#include "Zombie.h"
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

class District
{ /// District Class
private:

public:
    string name;
    Alarmed alarm;
    Ignorant ignorant;
    Zombie zombie;
    District();
    District(string districtName);
    void set_aware(string name);
    void set_ignorant(string name);
    void set_zombie(string name);
    int countainer_count(); // overloaded function
    float rate_of_growth(); // overloaded function
    void interact_A_Z(float prob); // Alarmed and Zombie
    void interact_I_Z(float prob); // Ignorant and Zombie
    void interact_A_I(float prob); // Alarmed and Ignorant
    

    /*interact method that invokes citizens interact*/
};

#endif