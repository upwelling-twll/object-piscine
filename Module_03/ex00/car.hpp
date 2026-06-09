#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "colors.hpp"
#include "engine.hpp"
#include "transmission.hpp"
#include "brakes.hpp"
#include "steeringSystem.hpp"

class Car
{
    private:
        Engine          engine;
        Transmission    transmission;
        Brakes          brakes;
        SteeringSystem  steeringSystem;


    public:
        Car(){
            std::cout << CAR << "Car created" << RESET << std::endl;
        };

        ~Car(){
            std::cout << CAR << "Car destroyed" << RESET << std::endl;
        };

        void start(){
            engine.start();
        }

        void stop(){
            engine.stop();
        }

        void accelerate(int speed){
            if (speed > 0 && speed < 60)
                transmission.accelerate(speed);
            else
                std::cout << CAR << "Invalid speed" << RESET << std::endl;
        }

        void shift_gears_up(){
            transmission.shift_up();
        }

        void shift_gears_down(){
            transmission.shift_down();
        }

        void reverse(){
            transmission.reverse();
        }

        void turn_wheel(int angle){
            if (angle > -45 && angle < 45)
                steeringSystem.turn(angle);
            else
                std::cout << CAR << "Invalid angle" << RESET << std::endl;
        }

        void straighten_wheel(){
            steeringSystem.straighten();
        }

        void apply_force_on_brakes(int force){
            if (force > 0 && force < 100)
                brakes.apply_force(force);
            else
                std::cout << CAR << "Invalid force" << RESET << std::endl;
        }

        void apply_emergency_brakes(){
            brakes.apply_emergency();
        }
};

#endif