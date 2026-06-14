#ifndef LINE_HPP
#define LINE_HPP
#include <iostream>
#include "Vector2.hpp"

class Line
{
    private:
        Vector2 start;
        Vector2 end;

    public:
        Line(Vector2 start, Vector2 end);
        ~Line();

        friend class Graph; // Allow Graph to access private members of Line
};

#endif