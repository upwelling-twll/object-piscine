#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include "colors.hpp"

class Engine
{
    bool    is_running;
    
    public:
        Engine() : is_running(false) {};
        ~Engine() {};

        void start(){
            if (is_running) {
                std::cout << ENGINE << "Engine is already running" << RESET << std::endl;
                return;
            }
            is_running = true;
            std::cout << ENGINE << "Engine started" << RESET << std::endl;
        }

        void stop(){
            if (!is_running) {
                std::cout << ENGINE << "Engine is already stopped" << RESET << std::endl;
                return;
            }
            is_running = false;
            std::cout << ENGINE << "Engine stopped" << RESET << std::endl;
        }

        void accelerate(int speed){
            if (!is_running) {
                std::cout << ENGINE << "Cannot accelerate, engine is not running" << RESET << std::endl;
                return;
            }
            std::cout << ENGINE << "Accelerating on " << speed << " km/h" << RESET << std::endl;
        }

        bool engine_is_running(){
            return is_running;
        }
};

#endif