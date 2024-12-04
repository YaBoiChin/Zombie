
#ifndef _CITIZENS_H_
#define _CITIZENS_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;
template <typename T>
class Citizen
{
private:
    string name;
public:
    Citizen(){name = "N/A";};
    Citizen(string name):name(name){};
    vector<string> list; // container of citizens
    virtual void Interact(Citizen<T> person) = 0; // allowing citizens to interact with one another and changing which container they are each stored in
    virtual string report_self() = 0;
};

#endif


// #ifndef _CITIZENS_H_
// #define _CITIZENS_H_

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// // Base class template for Citizen
// template <typename T>
// class Citizen {
// private:
//     string name;

// public:
//     // Default constructor and parameterized constructor
//     Citizen() : name("N/A") {}
//     Citizen(const string& name) : name(name) {}

//     // Virtual destructor to ensure proper cleanup in derived classes
//     virtual ~Citizen() = default;

//     // Static list of all citizens (shared by all instances of Citizen and its subclasses)
//     static vector<string> list;

//     // Virtual function to allow interactions between citizens
//     virtual void Interact(Citizen<T>& person) = 0;

//     // Virtual function to report information about the citizen
//     virtual string report_self() const = 0;
// };

// template <typename T>
// vector<string> Citizen<T>::list;  // Initialize the static member outside the class

// #endif





// #include "Citizens.h"

// // Derived class representing a specific type of citizen
// class Soldier : public Citizen<Soldier> {
// public:
//     Soldier(const string& name) : Citizen<Soldier>(name) {}

//     // Implementing the Interact method
//     void Interact(Citizen<Soldier>& person) override {
//         cout << name << " is interacting with " << person.report_self() << endl;
//     }

//     // Implementing the report_self method
//     string report_self() const override {
//         return "I am a Soldier, named " + name;
//     }
// };
