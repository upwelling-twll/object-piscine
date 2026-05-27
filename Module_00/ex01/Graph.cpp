#include "Graph.hpp"

void Grapth::addPoint(Vector2 point)
{
    if (point.x < 0 || point.x > size.x || point.y < 0 || point.y > size.y)
        throw "Point must be within the graph size";
    points.push_back(point);
}

Graph::Graph(Vector2 size) : size(size)
{
    if (size.x <= 0 || size.y <= 0)
        throw "Size must be greater than 0";
    if (size.x > 100 || size.y > 100)
        throw "Size must be less than 100";
}

Graph::~Graph()
{
   for (std::list<Vector2>::iterator it = points.begin(); \
    it != points.end(); ++it)
        points.erase(it);
}