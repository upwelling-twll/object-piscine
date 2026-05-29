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
        // Print y-axis labels
        if (size.y >= 10 && y < 10) // Print labels every 5 units for larger graphs
            std::cout << y << "  ";
        else
            std::cout << y << " ";
        // Print graph points
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
    // Print x-axis labels
    if (size.y >= 10) 
        std::cout << "   ";
    else
        std::cout << "  ";
    for (int x = 0; x <= width; ++x)
        std::cout << x << " ";
    std::cout << std::endl;
}

void Graph::drawLinesBresenham(Line line)
{
    int x1 = static_cast<int>(line.start.x);
    int y1 = static_cast<int>(line.start.y);
    int x2 = static_cast<int>(line.end.x);
    int y2 = static_cast<int>(line.end.y);

    int dx = std::abs(x2 - x1); // absolute difference in x
    int dy = std::abs(y2 - y1); // absolute difference in y
    int sx = (x1 < x2) ? 1 : -1; // step direction in x
    int sy = (y1 < y2) ? 1 : -1; // step direction in y
    int err = dx - dy; // error used to decide when to step in y direction
    while (true)
    {
        // Add the current point to the graph
         
        addPoint(Vector2(static_cast<float>(x1), static_cast<float>(y1)));
        // std::cout << "Adding line point (" << x1 << ", " << y1 << ") from Bresenham's algorithm" << std::endl;

        // Check if we've reached the end point
        if (x1 == x2 && y1 == y2)
            break;
        // Calculate error and adjust points
        int err2 = 2 * err;
        // Move in x direction
        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        // Move in y direction
        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Graph::drawLines()
{
    for (std::list<Line>::iterator it = lines.begin(); it != lines.end(); ++it)
    {
        drawLinesBresenham(*it);
    }
    drawASCII();
    return;
}

void Graph::draw()
{
    if (lines.empty())
        drawASCII();
    else
        drawLines();
}

// TODO
void Graph::exportPNG()
{
    std::cout << "exporting PNG graph" << std::endl ;
    unsigned char* image = new unsigned char[static_cast<int>(size.x) * static_cast<int>(size.y) * 3];
    for (std::list<Vector2>::iterator it = points.begin(); it != points.end(); ++it)
    {
        //setting pixel color to white for each point
        int x = static_cast<int>(it->x);
        int y = static_cast<int>(it->y);
        int index = (y * static_cast<int>(size.x) + x) * 3;
        image[index] = 255;     // Red
        image[index + 1] = 255; // Green
        image[index + 2] = 255; // Blue 
    }
    
}

void Graph::readPointsFromFile(int fd)
{
    char buffer[256];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytesRead] = '\0'; // Null-terminate the buffer
        std::istringstream iss(buffer);
        float x;
        float y;
        while (iss >> x >> y) // Read pairs of coordinates from the buffer
        {
            addPoint(Vector2(x, y));
        }
    }
}

void Graph::addPoint(Vector2 point)
{   
    // std::cout << "Adding point (" << point.x << ", " << point.y << ")" << std::endl;
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

Graph::Graph(const Vector2 size) : size(size)
{
    if (size.x <= 0 || size.y <= 0)
        throw "Size must be greater than 0";
    if (size.x > 10 || size.y > 10)
        throw "Size must be less than 11";
}

Graph::~Graph()
{
    std::cout << "Graph destroyed" << std::endl;
    
        points.clear();
}