#include "Line.hpp"

Line::Line(Vector2 start, Vector2 end) : start(start), end(end)
{
    std::cout << "Line created from (" << start.x << ", " << start.y << ") to ("
              << end.x << ", " << end.y << ")" << std::endl;
}

Line::~Line()
{
}
