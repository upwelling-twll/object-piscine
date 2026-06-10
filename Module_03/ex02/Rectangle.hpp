#ifndef Rectangle_HPP
#define Rectangle_HPP

class Rectangle : public Shape
{
    private:
        int length;
        int height;

    public:
        int area()
        {
            return (length * height);
        }
        
        int perimeter()
        {
            return (2*(length + height));
        }

        Rectangle(int length, int height)
        {
            this->length = length;
            this->height = height;
        };

        ~Rectangle() {};
};

#endif