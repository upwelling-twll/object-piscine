#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
    public:
        virtual ~Shape(){};

        virtual int area() = 0;
        virtual int perimeter() = 0;
};

#endif