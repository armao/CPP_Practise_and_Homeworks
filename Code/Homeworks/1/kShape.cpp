#include "kShape.h"
#include <iostream>
#include "shape.h"


kShape stringToShape(const std::string& str)
{
    if (str == "rectangle" || str == "Rectangle" || str == "RECTANGLE")
        return kShape::rectangle;

    if (str == "square" || str == "Square" || str == "SQUARE")
        return kShape::square;

    if (str == "circle" || str == "Circle" || str == "CIRCLE")
        return kShape::circle;

    if (str == "triangle" || str == "Triangle" || str == "TRIANGLE")
        return kShape::triangle;

    else return kShape::exception;
}

void cin_num_exception()
{
    std::cout << std::endl;
    std::cout << "Have to enter the number, Please retry again." << std::endl;
    std::cout << std::endl;
    std::string s;
    std::cin.clear();
    std::getline(std::cin, s, '\n');
}

void cin_num_rectangle()
{
    float width = 0.f;
    float height = 0.f;

    do
    {
        std::cout << "Please enter width and height, separated by space:  ";
        std::cin >> width >> height;

        if (std::cin.fail())
        {
            cin_num_exception();
        }

        else
        {
            rectangle r{ width, height };
            std::cout << std::endl;
            std::cout << r << std::endl;
            std::cout << std::endl;
            break;
        }

    } while (true);
}

void cin_num_square()
{
    float sideLength = 0.f;

    do
    {
        std::cout << "Please enter side length:  ";
        std::cin >> sideLength;

        if (std::cin.fail())
        {
            cin_num_exception();
        }

        else
        {
            square sq{ sideLength };
            std::cout << std::endl;
            std::cout << sq << std::endl;
            std::cout << std::endl;
            break;
        }

    } while (true);
}

void cin_num_circle()
{
    float radius = 0.f;

    do
    {
        std::cout << "Please enter radius:  ";
        std::cin >> radius;

        if (std::cin.fail())
        {
            cin_num_exception();
        }

        else
        {
            circle c{ radius };
            std::cout << std::endl;
            std::cout << c << std::endl;
            std::cout << std::endl;
            break;
        }

    } while (true);
}

void cin_num_triangle()
{
    float sideLength1 = 0.f;
    float sideLength2 = 0.f;
    float sideLength3 = 0.f;

    do
    {
        std::cout << "Please enter side lengths of triangle, separated by space:  ";
        std::cin >> sideLength1 >> sideLength2 >> sideLength3;

        if (std::cin.fail())
        {
            cin_num_exception();
        }

        else
        {
            try
            {
                triangle t{ sideLength1, sideLength2, sideLength3 };
                std::cout << std::endl;
                std::cout << t << std::endl;
                std::cout << std::endl;
                break;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
                std::cout << std::endl;
            }
        }

    } while (true);
}

void cin_shape_switcherV1(const std::string& str)
{
    kShape ks = std::move(stringToShape(str));

    switch (ks)
    {

    case kShape::rectangle:

        cin_num_rectangle();

        break;


    case kShape::square:

        cin_num_square();

        break;


    case kShape::circle:

        cin_num_circle();

        break;


    case kShape::triangle:

        cin_num_triangle();

        break;


    default:

        std::cout << std::endl;
        std::cout << "This isn't a shape (rectangle, square, circle, triangle)." << std::endl;
        std::cout << std::endl;

    }

}

void cin_shape_switcherV2(const std::string& str)
{

    if (str == "rectangle" || str == "Rectangle" || str == "RECTANGLE")
    {
        cin_num_rectangle();
    }

    if (str == "square" || str == "Square" || str == "SQUARE")
    {
        cin_num_square();
    }

    if (str == "circle" || str == "Circle" || str == "CIRCLE")
    {
        cin_num_circle();
    }

    if (str == "triangle" || str == "Triangle" || str == "TRIANGLE")
    {
        cin_num_triangle();
    }

    else
    {
        std::cout << std::endl;
        std::cout <<"\"" << str << "\" This isn't a shape (rectangle, square, circle, triangle)." << std::endl;
        std::cout << std::endl;
    }
}
