#include "car.hpp"
#include "colors.hpp"
#include <iostream>
int main()
{
    Car car;

    car.start();
    car.accelerate(30);
    car.shift_gears_up();
    car.turn_wheel(15);
    car.display_status();
    car.apply_force_on_brakes(200);
    car.display_status();
    car.apply_force_on_brakes(999);
    car.stop();

    car.stop();
    car.accelerate(30);
    car.turn_wheel(30);

    car.display_status();

    car.apply_emergency_brakes();
    car.stop();

    car.start();
    car.reverse();
    car.shift_gears_down();
    car.reverse();
    car.stop();
    car.start();
    car.reverse();
    car.accelerate(40);
    car.shift_gears_up();
    car.display_status();
    car.accelerate(40);
    car.shift_gears_down();

    car.reverse();


    return 0;
}