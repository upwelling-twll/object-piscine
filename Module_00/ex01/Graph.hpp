#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <iostream>

struct Vector2
{
    float x;
    float y;
};

class Graph
{
    private:
        Vector2             size;
        std::list<Vector2> points;

    public:
        Graph(Vector2 size);
        ~Graph();

        void draw();
        void addPoint(Vector2 point);
};

#endif