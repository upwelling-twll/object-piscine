#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <iostream>
// #include "Line.hpp"
struct Vector2
{
    float x;
    float y;
};

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


class Graph
{
    private:
        Vector2             size;
        std::list<Vector2> points;
        std::list<Line>    lines;

    public:
        Graph(Vector2 size);
        ~Graph();

        void drawASCII();
        void drawLines();
        // void drawPNG();
        void addLinePoints(Line line);
        void addPoint(Vector2 point);
        void addLine(Line line);
};

#endif