#ifndef Triangle_HPP
#define Triangle_HPP

class Triangle : public Shape
{
    private:
        int height;
        int base;
        int side1;
        int side2;

    public:
        int area()
        {
            return (base * height / 2);
        }
        
        int perimeter()
        {
            return (base + side1 + side2);
        }

        Triangle(int height, int base, int side1, int side2)
        {
            this->height = height;
            this->base = base;
            this->side1 = side1;
            this->side2 = side2;
        };

        ~Triangle() {};
};

#endif