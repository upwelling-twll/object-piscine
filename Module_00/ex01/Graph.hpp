#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <cmath>

#include "Vector2.hpp"
#include "Line.hpp"

#define WIDTH 5
#define HEIGHT 5

class Graph
{
    private:
        Vector2             size;
        std::list<Vector2> points;
        std::list<Line>    lines;

    public:
        Graph(const Vector2 size);
        ~Graph();

        void drawASCII();
        void drawLines();
        void draw();
        void addPoint(Vector2 point);
        
        void addLine(Line line);
        void drawLinesBresenham(Line line);
        
        void exportPNG();

        void readPointsFromFile(int fd);
        bool parsePoints(std::istringstream& iss, float* x, float* y);
};

#endif