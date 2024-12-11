#include "District.h"
#include <cstdlib>
#include <ctime>

District::District() {
    name = "N/A";
    std::srand(std::time(NULL));
}

District::District(std::string districtName) {
    name = districtName;
    std::srand(std::time(NULL));
}

int District::countainer_count() { // population of each district
    return alarm.getList().size() + ignorant.getList().size() + zombie.getList().size();
}

float District::rate_of_growth() { // overloaded function
    return 0;
}

void District::interact_A_Z(float prob) {
    int first, likelihood;

    likelihood = std::rand() % 100;

    if (likelihood < prob && zombie.getList().size() > 0) {
        // find a random person inside the alarmed list
        for (int x = 0; x < alarm.getList().size(); x++) {
            first = std::rand() % alarm.getList().size();
        }
        // changing the state of the person
        if (!alarm.getList().empty()) {
            zombie.getList().push_back(alarm.getList()[first]);
            alarm.getList().erase(alarm.getList().begin() + first);
        }
    }
}

void District::interact_I_Z(float prob) {
    int first, likelihood;

    likelihood = std::rand() % 100;

    if (likelihood < prob && zombie.getList().size() > 0) {
        // find a random person inside the ignorant list
        for (int x = 0; x < ignorant.getList().size(); x++) {
            first = std::rand() % ignorant.getList().size();
        }
        // changing the state of the person
        if (!ignorant.getList().empty()) {
            zombie.getList().push_back(ignorant.getList()[first]);
            ignorant.getList().erase(ignorant.getList().begin() + first);
        }
    }
}

void District::interact_A_I(float prob) {
    int first, likelihood;

    likelihood = std::rand() % 100;

    if (likelihood < prob && alarm.getList().size() > 0) {
        // find a random person inside the ignorant list
        for (int x = 0; x < ignorant.getList().size(); x++) {
            first = std::rand() % ignorant.getList().size(); // random index inside ignorant list
        }
        // changing the state of the person
        if (!ignorant.getList().empty()) {
            alarm.getList().push_back(ignorant.getList()[first]);
            ignorant.getList().erase(ignorant.getList().begin() + first);
        }
    }
}
