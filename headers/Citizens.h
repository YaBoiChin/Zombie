
#ifndef _CITIZENS_H_
#define _CITIZENS_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Citizen
{
private:
    string name;
public:
    Citizen(string name):name(name){};
    vector<string> list // container of citizens
    virtual void Interact(string person) = 0; // allowing citizens to interact with one another and changing which container they are each stored in
    virtual string report_self() = 0;
};

#endif