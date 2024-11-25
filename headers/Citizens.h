
#ifndef _CITIZENS_H_
#define _CITIZENS_H_


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Citizen {
    private:

    public: 
        vector<string> list; // container of type citizens
        virtual void Interact() = 0;
        virtual string report_self() = 0;
};

#endif