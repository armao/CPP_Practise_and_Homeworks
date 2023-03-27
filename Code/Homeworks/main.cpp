#include <iostream>
#include <iomanip>
#include <utility>
#include "shape.h"
#include <string>

enum class kShape
{
    rectangle=1,
    square,
    circle,
    triangle,
    close,
    exception,
};

kShape stringToShape(std::string str)
{
    if (str == "rectangle" || str == "Rectangle" || str == "RECTANGLE")
        return kShape::rectangle;

    if (str == "square" || str == "Square" || str == "SQUARE")
        return kShape::square;

    if (str == "circle" || str == "Circle" || str == "CIRCLE")
        return kShape::circle;

    if (str == "triangle" || str == "Triangle" || str == "TRIANGLE")
        return kShape::triangle;

    if (str == "close")
        return kShape::close;
   
    else return kShape::exception;
}

int main(int argc, char* argv[])
{
    // Please enter a shape (rectangle, square, circle, triangle): rectangle
    // Please enter width and height, separated by space: 5.1 3.4
    // rectangle(w: 5.1, h: 3.4, area: XXXX, perimeter: XXXX)
    bool notyet = true;
    std::string str;
    float num1 = 0.f;
    float num2 = 0.f;
    float num3 = 0.f;
    
    do
    {
        std::cout << "Please enter a shape(or enter \"close\" to end program):  ";
        std::cin >> str;
        kShape ks = stringToShape(str);

        switch (ks)
        {
            case kShape::rectangle:
            {
                std::cout << "Please enter width and height, separated by space:  ";
                std::cin >> num1 >> num2;
                rectangle r{ num1, num2 };
                std::cout << r << std::endl;
                break;
            }

            case kShape::square:
            {
                std::cout << "Please enter side length:  ";
                std::cin >> num1;
                square sq{ num1 };
                std::cout << sq << std::endl;
                break;
            }

            case kShape::circle:
            {
                std::cout << "Please enter radius:  ";
                std::cin >> num1;
                circle c{ num1 };
                std::cout << c << std::endl;
                break;
            }

            case kShape::triangle:
            {
                std::cout << "Please enter side lengths of triangle, separated by space:  ";
                std::cin >> num1 >> num2 >> num3;
                triangle t{ num1, num2, num3 };
                std::cout << t << std::endl;
                break;
            }

            case kShape::close:
            {
                std::cout << "bye bye!";
                notyet = false;
                break;
            }

            default:
            {
                std::cout << "Please enter a shape (rectangle, square, circle, triangle)." << std::endl;

            }
        }

    } while (notyet);

    return 0;
}
