#ifndef districts_HH
#define districts_HH


#include <string>
#include <vector>
#include "Alarmed.h"
#include "Ignorant.h"
#include "Zombie.h"


using namespace std;///// I will change this later

    class District {  ///District Class
        private:
            string name;
            Alarmed alarm;
            Ignorant ignorant;
            Zombie zombie;
            

        public:
            District(string districtName);

            void set_aware();
            void set_ignorant();
            void set_zombie();
        ///// Getter statements
            int getIgnorantCount();

            


        


    };




#endif