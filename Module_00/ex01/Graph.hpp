#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <cmath>

// #include "Line.hpp"

struct RGB
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class Vector2
{
    float x;
    float y;
public:
    Vector2(float x, float y) : x(x), y(y) {};
    float getX() const;
    float getY() const;

    friend class Graph;
    friend class Line;
};

struct Pixel
{
    Vector2 position;
    RGB color;
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