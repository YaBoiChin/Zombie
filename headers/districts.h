#ifndef districts_HH
#define districts_HH


#include <string>
#include <vector>
using namespace std;///// I will change this later

    class District {  ///District Class
        private:
            string name;
            vector<tuple<string, string>> awareList;
            vector<tuple<string, string>> zombieList;
            vector<tuple<string, string>> ingorantList;

        public:
            District(string districtName);

        ///// Getter statements
            string getName();
            int getzombieCount();
            int getAlarmedCount();
            int getIgnorantCount();

            void 


        ///// Setter statements
            void setIgnorantCount(int count);
            void setAlarmedCount(int count);
            void setZombieCount(int count);


    };




#endif