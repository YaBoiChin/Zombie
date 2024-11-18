#ifndef districts_HH
#define districts_HH


#include <string>
#include <vector>
using namespace std;        ///// I will change this later

    class District {
        private:
            string name;
            int zombieCount;
            int ignorantCount;
            int alarmedCount;



        public:
            District(string districtName, int zombies, int ignorant, int alarmed);

        ///// Getter statements
            string getName();
            int getzombieCount();
            int getAlarmedCount();
            int getIgnorantCount();


        ///// Setter statements
            void setIgnorantCount(int count);
            void setAlarmedCount(int count);
            void setZombieCount(int count);


    };




#endif