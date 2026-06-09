#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include <iostream>
#include "colors.hpp"

class Transmission
{
    int current_gear;
    int max_gear;
    bool is_reversing;

    public:
            Transmission() : current_gear(1), max_gear(5), is_reversing(false) {};
            ~Transmission() {};

        void shift_up(){
            if (current_gear < max_gear)
            {
                if (current_gear == 1 && is_reversing)
                    is_reversing = false;
                current_gear++;
                std::cout << TRANSMISSION << "Shifting up to gear " << current_gear << RESET << std::endl;
            }
            else
                std::cout << TRANSMISSION << "Already in highest gear" << RESET << std::endl;
        }

        void shift_down(){
            if (current_gear > 1) {
                current_gear--;
                std::cout << TRANSMISSION << "Shifting down to gear " << current_gear << RESET << std::endl;
            }
            else
                std::cout << TRANSMISSION << "Already in lowest gear" << RESET << std::endl;
        }

        void reverse(){
            if (is_reversing)
            {
                std::cout << TRANSMISSION << "Already in reverse" << RESET << std::endl;
                return;
            }
            if (current_gear == 1)
            {
                is_reversing = true;
                std::cout << TRANSMISSION << "Reversing" << RESET << std::endl;
            }
            else
                std::cout << TRANSMISSION << "Cannot reverse from current gear " << current_gear << RESET << std::endl;
        }

        std::string get_status(){
            std::string status = "Transmission is in gear " + std::to_string(current_gear) + (is_reversing ? " (reversing)" : "");
            return status;
        }

        bool is_in_reverse(){
            return is_reversing;
        }
};

#endif