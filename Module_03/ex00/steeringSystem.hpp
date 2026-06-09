#ifndef STEERING_SYSTEM_HPP
#define STEERING_SYSTEM_HPP

#include <iostream>
#include "colors.hpp"

class SteeringSystem
{
    public:
        SteeringSystem() {};
        ~SteeringSystem() {};

        void turn(int angle)
        {
            std::cout << STEERING_SYSTEM << "Turning wheel to " << angle << " degrees" << RESET << std::endl;
        }

        void straighten()
        {
            std::cout << STEERING_SYSTEM << "Straightening wheel" << RESET << std::endl;
        }
};

#endif