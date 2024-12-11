#include "Graph.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

Graph::Graph(District& _one, District& _two, District& _three, District& _four, District& _five)
    : one(_one), two(_two), three(_three), four(_four), five(_five) {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Initialize random seed
    District_map[1] = &one;
    District_map[2] = &two;
    District_map[3] = &three;
    District_map[4] = &four;
    District_map[5] = &five;
}

float Graph::district_citizens(float& s) {
    return s = (s / 100.0f) * 2000; // Calculate number of citizens
}

void Graph::Populate_districts(std::ifstream& Citizens, float pp_one, float pp_two, float pp_three, float pp_four, float pp_five) {
    std::vector<std::string> people;
    std::string firstName, lastName;

    district_citizens(pp_one);
    district_citizens(pp_two);
    pp_two += pp_one;
    district_citizens(pp_three);
    pp_three += pp_two;
    district_citizens(pp_four);
    pp_four += pp_three;
    district_citizens(pp_five);
    pp_five += pp_four;

    while (Citizens >> firstName >> lastName) {
        people.push_back(firstName + " " + lastName);
    }

    for (int i = 0; i < 2000; ++i) {
        if (i < pp_one) {
            if (i == 0) {
                one.alarm.getList().push_back(people[i]);
            } else if (i == 1) {
                one.zombie.getList().push_back(people[i]);
            } else {
                one.ignorant.getList().push_back(people[i]);
            }
        } else if (i < pp_two) {
            two.ignorant.getList().push_back(people[i]);
        } else if (i < pp_three) {
            three.ignorant.getList().push_back(people[i]);
        } else if (i < pp_four) {
            four.ignorant.getList().push_back(people[i]);
        } else if (i < pp_five) {
            five.ignorant.getList().push_back(people[i]);
        }
    }
}

void Graph::processList(std::vector<std::string>& srcList, const std::string& probability, int curInt, std::vector<int>& targets, std::vector<std::string>& temp) {
    for (std::vector<std::string>::iterator it = srcList.begin(); it != srcList.end();) {
        if (isMoved(probability)) {
            int target = moveOver(curInt);
            temp.push_back(*it);
            targets.push_back(target);
            it = srcList.erase(it);
        } else {
            ++it;
        }
    }
}

void Graph::Migrate() {
    Scramble(one, 1);
    Scramble(two, 2);
    Scramble(three, 3);
    Scramble(four, 4);
    Scramble(five, 5);
}

void Graph::Scramble(District& cur, int curInt) {
    std::vector<std::string> tempA, tempI, tempZ;
    std::vector<int> targetNumsA, targetNumsI, targetNumsZ;

    // Process the lists using the general processList function
    processList(cur.alarm.getList(), "High", curInt, targetNumsA, tempA);
    processList(cur.ignorant.getList(), "Low", curInt, targetNumsI, tempI);
    processList(cur.zombie.getList(), "Low", curInt, targetNumsZ, tempZ);

    for (int i = 0; i < tempA.size(); ++i) {
        District_map[targetNumsA[i]]->alarm.getList().push_back(tempA[i]);
    }
    for (int i = 0; i < tempI.size(); ++i) {
        District_map[targetNumsI[i]]->ignorant.getList().push_back(tempI[i]);
    }
    for (int i = 0; i < tempZ.size(); ++i) {
        District_map[targetNumsZ[i]]->zombie.getList().push_back(tempZ[i]);
    }
}

int Graph::moveOver(int currentDistrict) {
    int attempt = 0;
    while (attempt < 100) {
        int index = std::rand() % 5;
        if (District_graph[currentDistrict - 1][index]) {
            return index + 1;
        }
        ++attempt;
    }
    return currentDistrict; // If no valid district found, stay in the same district
}

bool Graph::isMoved(std::string probability) {
    if (probability == "High") {
        return (std::rand() % 100 < 75);
    }
    return (std::rand() % 100 < 30);
}

void Graph::Quarantine(int district) {
    for (int i = 0; i < 5; ++i) {
        District_graph[district - 1][i] = false;
        District_graph[i][district - 1] = false;
    }
}
