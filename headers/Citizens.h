
#ifndef _CITIZENS_H_
#define _CITIZENS_H_


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Citizen {
    private:
        // int state; // primitive type, 0- Zombie, 1 - Alarmed, 2 - Ignorant

    public: 
        vector<string> list; // container of type citizens
        virtual void Interact() = 0;

};

#endif