#include <iostream>
#include "Graph.h"
#include "Citizens.h"
#include "Districts.h"
using namespace std;

bool isValidProportion (float X, float Y, float Z){
    float total = X + Y + Z;
    return total ==100; 
}

bool isValidPercentage ( float first , float second, float third, float fourth, float fifth){ //bool function to check validity of percentage (district)
   float total = first + second + third + fourth + fifth;
    return total == 100; 
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

    Graph town(downtown,medicalHill,Soho,burbs,whitworth);
    ifstream Denizens;
/*
o	X, the likelihood of an ignorant person becoming a zombie if bitten.
o	Y, the likelihood of an ignorant person becoming alarmed if alerted by an alarmed person.
o	Z, the likelihood of an alarmed person becoming a zombie if bitten.
o	D, the number of days you want to the simulation to entail.
o	The percentage of people who start out in each district.

*/
    cout<<"Enter the likelihood of an ignorant person becoming a zombie if bitten:";
    cin>>X;
    cout<<"Enter the likelihood of an ignorant person becoming alarmed if alerted by an alarmed person:";
    cin>>Y;
    cout<<"Enter the likelihood of an alarmed person becoming a zombie if bitten:";
    cin>>Z;
    cout<<"Enter the number of days you want to the simulation to entail";
    cin>>days;
    
    float first,second,third,fourth,fifth;

    cout<<"Enter percentage of people in Downtown";
    cin>>first;
    cout<<"Enter percentage of people in Medical Hill";
    cin>>second;
    cout<<"Enter percentage of people in Soho";
    cin>>third;
    cout<<"Enter percentage of people in Burbs";
    cin>>fourth;
    cout<<"Enter percentage of people in whitworth";
    cin>>fifth;

    if (isValidProportion(X,Y,Z)){ //if statement to check validity of percentage 
        cout << "Input Recieved" << endl;
    } else {
        cout << "INVALID : The total percentage does not equal 100." << endl;
        valid = false;
        }


    if (isValidPercentage(first,second,third,fourth,fifth)){ //if statement to check validity of percentage 
        cout << "Input Recieved" << endl;
    } else {
        cout << "INVALID : The total percentage does not equal 100." << endl;
        valid = false;
        }

    if (valid){
        Denizens.open("Denizens.txt");
        if(Denizens.fail()){
            cout<<"Did not open"<<endl;
            return 1;
        }
        town.Populate_districts(Denizens,first,second,third,fourth,fifth);
        

        for(int t = 0; t < (24*days); t++){
            town.Migrate();
            /* downtown.interact();
            medicalHill.interact();
            Soho.interact();
            burbs.interact();
            whitworth.interact(); */
        }
    }
    
    return 0;


}


                


  