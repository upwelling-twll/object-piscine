#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>

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

        void addPoint(Vector2 point);
        void draw();
};

#endif