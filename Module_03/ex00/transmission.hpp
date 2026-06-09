#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include <iostream>
#include "colors.hpp"

class Transmission
{
    int current_speed;
    int current_gear;
    int max_gear;

    public:
            Transmission() : current_speed(0), current_gear(1), max_gear(5) {};
            ~Transmission() {};

        void accelerate(int speed){
            std::cout << TRANSMISSION << "Accelerating to " << speed << " km/h" << RESET << std::endl;
        }

        void shift_up(){
            std::cout << TRANSMISSION << "Shifting up" << RESET << std::endl;
        }

        void shift_down(){
            std::cout << TRANSMISSION << "Shifting down" << RESET << std::endl;
        }

        void reverse(){
            std::cout << TRANSMISSION << "Reversing" << RESET << std::endl;
        }
};

#endif