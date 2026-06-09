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

        int current_speed;
        int max_speed;


    public:
        Car() : current_speed(0), max_speed(60) {
            std::cout << CAR << "Car created" << RESET << std::endl;
        };

        ~Car(){
            std::cout << CAR << "Car destroyed" << RESET << std::endl;
        };

        void start(){
            engine.start();
        }

        void stop(){
            if (current_speed > 0)
            {
                std::cout << CAR << "Cannot stop the car while it is moving" << RESET << std::endl;
                return;
            }
            engine.stop();
        }

        void accelerate(int speed)
        {
            if (engine.engine_is_running())
            {
                if (speed > 0 && speed < 60)
                {
                    if (transmission.is_in_reverse() && speed + current_speed > 20)
                    {
                        std::cout << CAR << "Cannot accelerate to " << speed << " km/h while in reverse" << RESET << std::endl;
                        return;
                    }
                    if (!transmission.is_in_reverse() && speed + current_speed > max_speed)
                    {
                        std::cout << CAR << "Cannot accelerate to " << speed << " km/h, exceeds max speed" << RESET << std::endl;
                        return;
                    }
                    current_speed += speed;
                    engine.accelerate(speed);
                }
                else
                    std::cout << CAR << "Invalid speed: " << speed << RESET << std::endl;
            }
            else
                std::cout << CAR << "Cannot accelerate, engine is not running" << RESET << std::endl;
        }

        void shift_gears_up(){
            transmission.shift_up();
        }

        void shift_gears_down(){
            transmission.shift_down();
        }

        void reverse(){
            if (current_speed > 0 && !transmission.is_in_reverse())
            {
                std::cout << CAR << "Cannot switch to reverse while the car is moving forward" << RESET << std::endl;
                return;
            }
            transmission.reverse();
        }

        void turn_wheel(int angle){
            if (angle > -45 && angle < 45)
                steeringSystem.turn(angle);
            else
                std::cout << CAR << "Invalid angle " << angle << " for steering system" << RESET << std::endl;
        }

        void straighten_wheel(){
            steeringSystem.straighten();
        }

        void apply_force_on_brakes(int force){
            if (!engine.engine_is_running())
            {
                std::cout << CAR << "Engine is not running, applying brakes with reduced force" << RESET << std::endl;
                force = force * 0.2;
                current_speed -= force * 0.1;
                if (current_speed < 0)
                    current_speed = 0;
               
            }
            if (force > 0 && force < 1000)
            {
                brakes.apply_force(force);
                current_speed -= force * 0.1;
                if (current_speed < 0)
                    current_speed = 0;
            }
            else
                std::cout << CAR << "Invalid force for brakes: " << force << RESET << std::endl;
        }

        void apply_emergency_brakes(){
            brakes.apply_emergency();
            current_speed = 0;
        }

        void display_status(){
            std::cout << CAR << "-------------------" << RESET << std::endl;
            std::cout << CAR << "****Car status: **** " << RESET << std::endl;
            if (engine.engine_is_running())
                std::cout << CAR << "Engine is running" << RESET << std::endl;
            else
                std::cout << CAR << "Engine is stopped" << RESET << std::endl;
            std::cout << CAR << "Current speed: " << this->current_speed << " km/h" << RESET << std::endl;
            std::cout << CAR << "Transmission: " << transmission.get_status() << RESET << std::endl;
            std::cout << CAR << "-------------------" << RESET << std::endl;
        }
};

#endif