#ifndef _CITIZENS_H_
#define _CITIZENS_H_

#include <iostream>
#include <vector>
#include <string>

class Citizen
{
private:
    //  list to hold all citizens' names
    std::vector<std::string> list;

public:
    Citizen() {}

    // Getter function to access the list
    std::vector<std::string>& getList() {
        return list;
    }

    // Virtual function to show how each citizen speaks
    virtual void speak(const Citizen& other) const = 0;
};

#endif
