#ifndef IEDGECOSTCALCULATOR_HPP
#define IEDGECOSTCALCULATOR_HPP
#include <iostream>


class IEdgeCostCalculator
{
    public:
    virtual double edgeCost(const Train&, const Rail&) const = 0;
};


class PhysicsEngine;

class  TravelTimeCalculator: public IEdgeCostCalculator
{
private:
    PhysicsEngine physics;

public:
    double edgeCost(const Train&, const Rail&) const override;
};

#endif