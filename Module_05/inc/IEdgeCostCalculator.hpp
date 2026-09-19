#ifndef IEDGECOSTCALCULATOR_HPP
#define IEDGECOSTCALCULATOR_HPP
#include <iostream>
#include "Train.hpp"
#include "Rail.hpp"
#include "math.h"
#include "Logger.hpp"

class Train;
class Rail;

class IEdgeCostCalculator
{
    public:

    virtual double edgeCost(const Train& train, const Rail& rail) const = 0;
    virtual ~IEdgeCostCalculator() = default;

};

class PhysicsEngine
{
    private:

    double _gravity = 9.81;       // m/s^2
    double _safetyMargin = 1.0;   // e.g. braking safety factor, or 1.0 if unused

    double Mass(double weight) const {
        return weight*1000; // Assuming weight is in tons, converting to kg
    }
    double Speed(double time, double distance) const {
        return (distance / time);
    }
    double Distance(double speed, double time) const {
        return speed * time;
    }
    double Time(double distance, double speed) const {
        return distance / speed;
    }
    double NewtonForce(double mass, double acceleration) const {
        return mass * acceleration;
    }

    //friction is calculated as F = m * g * cof, where cof is the coefficient of friction
    double FrictionForce(double mass, double cof) const {
        return mass * _gravity * cof;
    }
    //accelerationForce in kN (from train data), mass in kg (from train data)
    double Acceleration(double accelerationForce, double mass) const {
        return (accelerationForce * 1000) / mass;
    }
    //decelerationForce in kN (from train data), mass in kg (from train data)
    double Deceleration(double decelerationForce, double mass) const {
        return decelerationForce / mass;
    }
    //acceleration force taking into account friction, acceleration and deceleration
    double cleanAccelerationForce(double accelerationForce, double frictionForce) const {
        return accelerationForce - frictionForce;
    }
    //clean acceleration in m/s^2, mass in kg (from train data) taking into account friction, acceleration and deceleration
    double cleanAcceleration(double cleanForce, double mass) const {
        return cleanForce / mass;
    }
    //decceleration force taking into account friction, acceleration and deceleration
    double cleanDecelerationForce(double decelerationForce, double frictionForce) const {
        return decelerationForce + frictionForce;
    }
    //clean deceleration in m/s^2, mass in kg (from train data)
    double cleanDeceleration(double cleanForce, double mass) const {
        return cleanForce / mass;
    }
    //convert speed from km/h to m/s
    double kmhToMs(double speed) const {
        return speed / 3.6;
    }
    //time to accelerate to a certain speed with a given acceleration
    double AccelerationTime(double speed, double acceleration) const {
        return speed / acceleration;
    }
    double AccelerationDistance(double speed, double acceleration) const {
        return (speed * speed) / (2 * acceleration);
    }
    //deceleration is breaking acceleration 
    double BrakingTime(double speed, double deceleration) const {
        return speed / deceleration;
    }
    double BrakingDistance(double speed, double deceleration) const {
        return (speed * speed) / (2 * deceleration);
    }


    double SpeedWithAcceleration(double initialSpeed, double acceleration, double time) const {
        return initialSpeed + (acceleration * time);
    }
    double SpeedWithDeceleration(double initialSpeed, double deceleration, double time) const {
        return initialSpeed - (deceleration * time);
    }
    double StoppingDistance(double speed, double deceleration) const {
        return (speed * speed) / (2 * deceleration);
    }
    double DistanceWithAcceleration(double initialSpeed, double acceleration, double time) const {
        return (initialSpeed * time) + (0.5 * acceleration * time * time);
    }
    double DistanceWithDeceleration(double initialSpeed, double deceleration, double time) const {  
        return (initialSpeed * time) - (0.5 * deceleration * time * time);
    }
    double AccelerationSpeed(double initialSpeed, double acceleration, double distance) const {
        return std::sqrt((initialSpeed * initialSpeed) + (2 * acceleration * distance));
    }

    public:
    double calculateTravelTime(const Train& train, const Rail& rail) const {
        // Implement the logic to calculate travel time based on train and rail characteristics
        // This is a placeholder implementation
        auto& log = railways::Logger::get();
        double mass = Mass(train.getWeight());
        log.debug(std::format("train mass {}", std::to_string(mass)));
        double friction = FrictionForce(mass, train.getCOF());
        log.debug(std::format("train friction {}", std::to_string(friction)));
    
        double accelerationForce = train.getAcceleration() * 1000.0; // Assuming acceleration is in kN
        log.debug(std::format("train accelerationForce {}", std::to_string(accelerationForce)));
        double netAcceleration = cleanAcceleration(accelerationForce - friction, mass);
        log.debug(std::format("train netAcceleration {}", std::to_string(netAcceleration)));

        //convert rail parameters to m/s and m
        double distance = rail.getLength() * 1000; // Convert km to m
        log.debug(std::format("rail distance {}", std::to_string(distance)));
        double speedLimit = kmhToMs(rail.getSpeedLimit()); // Convert km/h to m/s
        log.debug(std::format("rail speedLimit {}", std::to_string(speedLimit)));
        
        //deceleration
        double brakeForce = train.getDeceleration() * 1000.0; // Assuming deceleration is in kN
        log.debug(std::format("train brakeForce {}", std::to_string(brakeForce)));
        double netDeceleration = cleanDeceleration(brakeForce + friction, mass);
        log.debug(std::format("train netDeceleration {}", std::to_string(netDeceleration)));

        //calculate distance to reach speed limit
        double accelerationDistance = AccelerationDistance(speedLimit, netAcceleration);
        log.debug(std::format("train accelerationDistance {}", std::to_string(accelerationDistance)));
        //calculate braking distance from speed limit to stop
        double brakingDistance = BrakingDistance(speedLimit, netDeceleration);
        log.debug(std::format("train brakingDistance {}", std::to_string(brakingDistance)));

        if (accelerationDistance + brakingDistance <= distance) {
            // The train cannot reach the speed limit before it needs to start braking
            // Calculate the maximum speed it can reach within the available distance
            log.debug(std::format("train cannot reach speed limit, calculating peak speed"));
            double timeToMaxSpeed = AccelerationTime(speedLimit, netAcceleration);
            log.debug(std::format("train timeToMaxSpeed {}", std::to_string(timeToMaxSpeed)));
            double timeToStop = BrakingTime(speedLimit, netDeceleration);
            log.debug(std::format("train timeToStop {}", std::to_string(timeToStop)));
            double cruisingDistance = distance - (accelerationDistance + brakingDistance);
            log.debug(std::format("train cruisingDistance {}", std::to_string(cruisingDistance)));
            double timeAtMaxSpeed = Time(cruisingDistance, speedLimit);
            log.debug(std::format("train timeAtMaxSpeed {}", std::to_string(timeAtMaxSpeed)));
            log.debug(std::format("train total time {}", std::to_string(timeToMaxSpeed + timeAtMaxSpeed + timeToStop)));
            return timeToMaxSpeed + timeAtMaxSpeed + timeToStop;
        }
        else {
            // The train can reach the speed limit and then cruise at that speed
            log.debug(std::format("train can reach speed limit, calculating total time"));
            double peakSpeed = std::sqrt((2.0 * distance * netAcceleration * netDeceleration)/(netAcceleration + netDeceleration));
            log.debug(std::format("train peakSpeed {}", std::to_string(peakSpeed)));
            double timeToMaxSpeed = AccelerationTime(peakSpeed, netAcceleration);
            log.debug(std::format("train timeToMaxSpeed {}", std::to_string(timeToMaxSpeed)));
            double timeToStop = BrakingTime(speedLimit, netDeceleration);
            log.debug(std::format("train timeToStop {}", std::to_string(timeToStop)));
            log.debug(std::format("train total time {}", std::to_string(timeToMaxSpeed + timeToStop)));
            return timeToMaxSpeed + timeToStop;
        }
    }
};

class  TravelTimeCalculator: public IEdgeCostCalculator
{
    private:

    PhysicsEngine physics;
    
    public:

    double edgeCost(const Train& train, const Rail& rail) const override
    {
        auto& log = railways::Logger::get();
        //uses rail characteresics like speed limit and lenght
        //uses train characteristics like acceleration, deceleration, etc. 
        log.debug(std::format("checking egdeCost for rail"));
	    double result = physics.calculateTravelTime(train, rail);
        log.debug("calculateTravelTime returned");
        return result;
    }

    TravelTimeCalculator() = default;
};

#endif