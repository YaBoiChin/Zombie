#include "Graph.h"

Graph::Graph(District& _one, District& _two, District& _three, District& _four, District& _five)
    : one(_one), two(_two), three(_three), four(_four), five(_five) {
    srand(static_cast<unsigned>(time(NULL))); // Initialize random seed
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
            (i == 0 ? one.alarm.list : (i == 1 ? one.zombie.list : one.ignorant.list)).push_back(people[i]);
        } else if (i < pp_two) {
            two.ignorant.list.push_back(people[i]);
        } else if (i < pp_three) {
            three.ignorant.list.push_back(people[i]);
        } else if (i < pp_four) {
            four.ignorant.list.push_back(people[i]);
        } else if (i < pp_five) {
            five.ignorant.list.push_back(people[i]);
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
    auto processList = [&](std::vector<std::string>& srcList, const std::string& probability, std::vector<int>& targets, std::vector<std::string>& temp) {
        for (auto it = srcList.begin(); it != srcList.end();) {
            if (isMoved(probability)) {
                int target = moveOver(curInt);
                temp.push_back(*it);
                targets.push_back(target);
                it = srcList.erase(it);
            } else {
                ++it;
            }
        }
    };

    std::vector<std::string> tempA, tempI, tempZ;
    std::vector<int> targetNumsA, targetNumsI, targetNumsZ;

    processList(cur.alarm.list, "High", targetNumsA, tempA);
    processList(cur.ignorant.list, "Low", targetNumsI, tempI);
    processList(cur.zombie.list, "Low", targetNumsZ, tempZ);

    for (size_t i = 0; i < tempA.size(); ++i) District_map[targetNumsA[i]]->alarm.list.push_back(tempA[i]);
    for (size_t i = 0; i < tempI.size(); ++i) District_map[targetNumsI[i]]->ignorant.list.push_back(tempI[i]);
    for (size_t i = 0; i < tempZ.size(); ++i) District_map[targetNumsZ[i]]->zombie.list.push_back(tempZ[i]);
}

int Graph::moveOver(int currentDistrict) {
    int attempt = 0;
    while (attempt < 100) {
        int index = rand() % 5;
        if (District_graph[currentDistrict - 1][index]) {
            return index + 1;
        }
        ++attempt;
    }
    return currentDistrict; // If no valid district found, stay in the same district
}

bool Graph::isMoved(std::string probability) {
    return (probability == "High" ? (rand() % 100 < 75) : (rand() % 100 < 30));
}

void Graph::Quarantine(int district) {
    for (int i = 0; i < 5; ++i) {
        District_graph[district - 1][i] = false;
        District_graph[i][district - 1] = false;
    }
}