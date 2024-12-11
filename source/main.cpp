#include <iostream>
#include "Graph.h"
#include "Citizens.h"
#include "District.h"

using namespace std;


bool isValidPercentage ( float first , float second, float third, float fourth, float fifth){ //bool function to check validity of percentage (district)
   float total;
   total= first + second + third + fourth + fifth;
    return (total == 100); 
}

void District_interact_AZ(District& a,float b){ // yes
    a.interact_A_Z(b);
}
void District_interact_AI(District& a, float b){ // yes
    a.interact_A_I(b);
}
void District_interact_IZ(District& a, float b){ // yes
    a.interact_I_Z(b);
}

void DistrictSim(District& a, float az, float ai, float iz){ //no
    District_interact_AI(a,ai);
    District_interact_AZ(a,az);
    District_interact_IZ(a,iz);
}
string concat(int i, District& example){
    return (i + ","+ example.name + "," + "Alarmed," + to_string(example.alarm.getList().size()) + "," + 
            "ignorant," + to_string(example.ignorant.getList().size()) + "zombie," + to_string(example.zombie.getList().size())+ "Total," + to_string(example.countainer_count()));
}
void writeToCSV(string& filename, vector<string> data) {
    // Open a file stream in write mode
    ofstream file(filename);

    // Check if the file stream is open
    if (!file.is_open()) {
        cout << "Failed to open the file: " << filename <<endl;
        return;
    }

    // Write headers
    file << "Data";

    // Write town data
    for (int i = 0; i < data.size(); ++i) {
        
            cout<<data[i]<<endl;     // Alarmed
             
    }

    // Close the file
    file.close();
    std::cout << "Data written to " << filename << " successfully." << std::endl;
}
int main() {
    float X, Y, Z;
    int days;
    bool valid = true;
    District downtown("Downtown");
    District medicalHill("Medical Hill");
    District Soho("Soho");
    District burbs("burbs");
    District whitworth("Whitworth");

    Graph town(whitworth, medicalHill, Soho, burbs, downtown);
    ifstream Denizens;
/*
o	X, the likelihood of an ignorant person becoming a zombie if bitten.
o	Y, the likelihood of an ignorant person becoming alarmed if alerted by an alarmed person.
o	Z, the likelihood of an alarmed person becoming a zombie if bitten.
o	D, the number of days you want to the simulation to entail.
o	The percentage of people who start out in each district.

*/
    // cout<<"Enter the likelihood of an ignorant person becoming a zombie if bitten:"<<endl;
    // cin>>X;
    // cout<<"Enter the likelihood of an ignorant person becoming alarmed if alerted by an alarmed person:"<<endl;
    // cin>>Y;
    // cout<<"Enter the likelihood of an alarmed person becoming a zombie if bitten:"<<endl;
    // cin>>Z;
    // cout<<"Enter the number of days you want to the simulation to entail:"<<endl;
    // cin>>days;
    X = 61;
    Y = 50;
    Z = 30;
    days = 28;
    float first,second,third,fourth,fifth;

    // cout<<"Enter percentage of people in Downtown:"<<endl;
    // cin>>first;
    // cout<<"Enter percentage of people in Medical Hill:"<<endl;
    // cin>>second;
    // cout<<"Enter percentage of people in Soho:"<<endl;
    // cin>>third;
    // cout<<"Enter percentage of people in Burbs:"<<endl;
    // cin>>fourth;
    // cout<<"Enter percentage of people in whitworth:"<<endl;
    // cin>>fifth;

     first = 20;
    second = 20;
     third = 20;
     fourth = 20;
     fifth = 20;
 
//  days = 28;
    
   if (isValidPercentage(first, second, third, fourth, fifth)) {
        cout << "Input received" << endl;
    } else {
        cout << "INVALID: The total percentage for districts does not equal 100." << endl;
        valid = false;
        return 1;
    }

    if (valid){
        Denizens.open("Denizens.txt");
        if(Denizens.fail()){
            cout<<"Did not open"<<endl;
            return 1;
        }
        
        town.Populate_districts(Denizens,first,second,third,fourth,fifth); // starting here
        vector<string> whitData, medData, sohoData, burbsData, downData;
        int end;
        end = 24 * days;
        
        for (int t = 0; t < end; t++){ 
            
            town.Migrate();
            DistrictSim(town.two, Z, Y, X);
            DistrictSim(town.three, Z, Y , X );
            DistrictSim(town.four, Z, Y, X);
            DistrictSim(town.five, Z, Y, X);

            whitData.push_back(concat(t, town.one));
            medData.push_back(concat(t, town.two));;
            sohoData.push_back(concat(t, town.three));;
            burbsData.push_back(concat(t, town.four));;
            downData.push_back(concat(t, town.five));
            
            cout << t << ": whitworth " <<  town.one.countainer_count() << endl;
            cout<<"Alarmed: "<<town.one.alarm.getList().size()<<endl;;
            cout<<"Ignorant:"<<town.one.ignorant.getList().size()<<endl;
            cout << "zombies: " << town.one.zombie.getList().size() <<endl;
            cout << t << ": MedicalHill: " << town.two.countainer_count() << endl;
            cout<<"Alarmed: "<<town.two.alarm.getList().size()<<endl;
            cout<<"Ignorant:"<<town.two.ignorant.getList().size()<<endl;
            cout << "zombies: " << town.two.zombie.getList().size() <<endl;
            cout << t << ": Soho " <<  town.three.countainer_count() << endl;
            cout<<"Alarmed: "<<town.three.alarm.getList().size()<<endl;
            cout<<"Ignorant:"<<town.three.ignorant.getList().size()<<endl;
            cout << "zombies: " << town.three.zombie.getList().size() <<endl;
            cout << t << ": Burbs: " << town.four.countainer_count() << endl;
            cout<<"Alarmed: "<<town.four.alarm.getList().size()<<endl;
            cout<<"Ignorant:"<<town.four.ignorant.getList().size()<<endl;
            cout << "zombies: " << town.four.zombie.getList().size() <<endl;
            cout << t << ": downtown " <<  town.five.countainer_count() << endl;
            cout<<"Alarmed: "<<town.five.alarm.getList().size()<<endl;
            cout<<"Ignorant:"<<town.five.ignorant.getList().size()<<endl;
            cout << "zombies: " << town.five.zombie.getList().size() <<endl;
            cout<<endl;
            cout<<endl;
         }
    }
    
    return 0;


}


                


  