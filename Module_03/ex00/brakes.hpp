#ifndef BRAKES_HPP
#define BRAKES_HPP 

#include <iostream>
#include "colors.hpp"

class Brakes
{
    public:
        Brakes() {};
        ~Brakes() {};

        void apply_force(int force){
            std::cout << BRAKES << "Applying " << force << " N of force on brakes" << RESET << std::endl;
        }

        void apply_emergency(){
            std::cout << BRAKES << "Applying emergency brakes" << RESET << std::endl;
        }

};

#endif