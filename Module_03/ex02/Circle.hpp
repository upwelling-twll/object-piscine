#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle : public Shape
{
    private:
        int radius;

    public:
        int area()
        {
            return (3.14 * radius * radius);
        }
        
        int perimeter()
        {
            return (2 * 3.14 * radius);
        }

        Circle(int radius) 
        {
            this->radius = radius;
        };

        ~Circle() {};
};

#endif