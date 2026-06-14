#ifndef LINE_HPP
#define LINE_HPP

class Vector2;

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

#endif