#include "Graph.hpp"

Line::Line(Vector2 start, Vector2 end) : start(start), end(end)
{
    std::cout << "Line created from (" << start.x << ", " << start.y << ") to ("
              << end.x << ", " << end.y << ")" << std::endl;
}

Line::~Line()
{
}

void Graph::drawASCII()
{
    int width = static_cast<int>(size.x);
    int height = static_cast<int>(size.y);

    std::cout << "ASCII graph" << std::endl;
    for (int y = height; y >= 0; --y)
    {
        std::cout << y << " ";
        for (int x = 0; x <= width; ++x)
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
            if (isPoint)
                std::cout << "* " ;
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int x = 0; x <= width; ++x)
        std::cout << x << " ";
    std::cout << std::endl;
}

void Graph::addLinePoints(Line line)
{
    for (int x = static_cast<int>(std::min(line.start.x, line.end.x)); \
        x <= static_cast<int>(std::max(line.start.x, line.end.x)); ++x)
    {
        for (int y = static_cast<int>(std::min(line.start.y, line.end.y)); \
            y <= static_cast<int>(std::max(line.start.y, line.end.y)); ++y)
        {
            addPoint(Vector2{static_cast<float>(x), static_cast<float>(y)});
            std::cout << "Adding line point (" << x << ", " << y << ") from line" << std::endl;
        }
    }
}

void Graph::drawLines()
{
    std::cout << "Lines graph" << std::endl;
    for (std::list<Line>::iterator it = lines.begin(); it != lines.end(); ++it)
    {
        addLinePoints(*it);
    }
    drawASCII();
}

// void Graph::drawPNG()
// {
//     std::cout << "PNG graph (not implemented)" << std::endl;
// }

void Graph::addPoint(Vector2 point)
{   
    std::cout << "Adding point (" << point.x << ", " << point.y << ")" << std::endl;
    if (point.x < 0 || point.x > size.x || point.y < 0 || point.y > size.y)
    {
        throw "Point must be within the graph size";
    }
    points.push_back(point);
}

void Graph::addLine(Line line)
{
    if (line.start.x < 0 || line.start.x > size.x || line.start.y < 0 || line.start.y > size.y ||
        line.end.x < 0 || line.end.x > size.x || line.end.y < 0 || line.end.y > size.y)
    {
        throw "Line must be within the graph size";
    }
    lines.push_back(line);
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