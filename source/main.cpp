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
X = 61;
Y = 50; 
Z = 30;
    // cout<<"Enter the likelihood of an ignorant person becoming a zombie if bitten:"<<endl;
    // cin>>X;
    // cout<<"Enter the likelihood of an ignorant person becoming alarmed if alerted by an alarmed person:"<<endl;
    // cin>>Y;
    // cout<<"Enter the likelihood of an alarmed person becoming a zombie if bitten:"<<endl;
    // cin>>Z;
    // cout<<"Enter the number of days you want to the simulation to entail:"<<endl;
    // cin>>days;
    
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
        
        int end = 24 * days;
        
        for (int t = 0; t < 672; t++){ 
            
            town.Migrate();
            // cout << t << ": " << town.one.countainer_count() << endl;
            // District_interact_AI(town.one, Y);
            // cout << t << ": alarm " << town.one.alarm.list.size() << endl;
            // cout << t << ": ignorant " << town.one.ignorant.list.size() << endl;
            // cout << t << ": zombie " << town.one.zombie.list.size() << endl;
            DistrictSim(town.one, Z, Y, X);
            DistrictSim(town.two, Z, Y, X);
            DistrictSim(town.three, Z, Y , X );
            DistrictSim(town.four, Z, Y, X);
            DistrictSim(town.five, Z, Y, X);

            cout << t << ": whitworth " <<  town.one.countainer_count() << endl;
            cout<<"Alarmed: "<<town.one.alarm.list.size()<<endl;
            cout<<"Ignorant:"<<town.one.ignorant.list.size()<<endl;
            cout << "zombies: " << town.one.zombie.list.size() <<endl;
            cout << t << ": MedicalHill: " << town.two.countainer_count() << endl;
            cout<<"Alarmed: "<<town.two.alarm.list.size()<<endl;
            cout<<"Ignorant:"<<town.two.ignorant.list.size()<<endl;
            cout << "zombies: " << town.two.zombie.list.size() <<endl;
            cout << t << ": Soho " <<  town.three.countainer_count() << endl;
            cout<<"Alarmed: "<<town.three.alarm.list.size()<<endl;
            cout<<"Ignorant:"<<town.three.ignorant.list.size()<<endl;
            cout << "zombies: " << town.three.zombie.list.size() <<endl;
            cout << t << ": Burbs: " << town.four.countainer_count() << endl;
            cout<<"Alarmed: "<<town.four.alarm.list.size()<<endl;
            cout<<"Ignorant:"<<town.four.ignorant.list.size()<<endl;
            cout << "zombies: " << town.four.zombie.list.size() <<endl;
            cout << t << ": downtown " <<  town.five.countainer_count() << endl;
            cout<<"Alarmed: "<<town.five.alarm.list.size()<<endl;
            cout<<"Ignorant:"<<town.five.ignorant.list.size()<<endl;
            cout << "zombies: " << town.five.zombie.list.size() <<endl;
            cout<<endl;
            cout<<endl;
         }
    }
    
    return 0;


}


                


  