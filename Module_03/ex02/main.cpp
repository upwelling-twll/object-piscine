#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

#include <iostream>

int main()
{
    Rectangle rectangle(2, 3);
    Triangle triangle(10, 5, 1, 1);
    Circle circle(10);

    std::cout << "Rectangle area: "<< rectangle.area() << std::endl;
    std::cout << "Triangle area: "<< triangle.area() << std::endl;
    std::cout << "Circle area: "<< circle.area() << std::endl;


    std::cout << "Rectangle perimeter: " << rectangle.perimeter() << std::endl;
    std::cout << "Triangle perimeter: " << triangle.perimeter() << std::endl;
    std::cout << "Circle perimeter: " << circle.perimeter() << std::endl;

    Shape *shapes[3];
    shapes[0] = &rectangle;
    shapes[1] = &triangle;
    shapes[2] = &circle;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Shape area: " << (shapes[i])->area() << std::endl;
    }
}