#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2
{
    private:

        float x;
        float y;
        
    public:

        Vector2(float x, float y);
        float getX() const;
        float getY() const;

        friend class Graph;
        friend class Line;
};

#endif