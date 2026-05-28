#include "Graph.hpp"

void Graph::draw()
{
    int width = static_cast<int>(size.x);
    int height = static_cast<int>(size.y);

    std::cout << "ASCII graph" << std::endl;
    for (int y = height; y >= 0; --y)
    {
        std::cout << y << " | ";
        for (int x = 0; x < width; ++x)
        {
            bool isPoint = false;
            for (std::list<Vector2>::iterator it = points.begin(); \
                it != points.end(); ++it)
            {
                if (static_cast<int>(it->x) == x && static_cast<int>(it->y) == y)
                {
                    isPoint = true;
                    break;
                }
            }
            // std::cout << "line" << std::endl;
            if (isPoint)
                std::cout << "*" ;
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}

void Graph::addPoint(Vector2 point)
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
    std::cout << "Graph destroyed" << std::endl;
    
        points.clear();
}