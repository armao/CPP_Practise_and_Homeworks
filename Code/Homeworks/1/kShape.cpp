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


void cin_num(const kShape& ks)
{
    float cin_num1 = 0.f;
    float cin_num2 = 0.f;
    float cin_num3 = 0.f;
    switch (ks)
    {
    case kShape::rectangle:

        do
        {
            std::cout << "Please enter width and height, separated by space:  ";
            std::cin >> cin_num1 >> cin_num2;

            if (std::cin.fail())
            {
                cin_num_exception();
            }

            else
            {
                rectangle r{ cin_num1, cin_num1 };
                std::cout << std::endl;
                std::cout << r << std::endl;
                std::cout << std::endl;
                break;
            }

        } while (true);

        break;


    case kShape::square:

        do
        {
            std::cout << "Please enter side length:  ";
            std::cin >> cin_num1;

            if (std::cin.fail())
            {
                cin_num_exception();
            }

            else
            {
                square sq{ cin_num1 };
                std::cout << std::endl;
                std::cout << sq << std::endl;
                std::cout << std::endl;
                break;
            }

        } while (true);

        break;


    case kShape::circle:

        do
        {
            std::cout << "Please enter radius:  ";
            std::cin >> cin_num1;

            if (std::cin.fail())
            {
                cin_num_exception();
            }

            else
            {
                circle c{ cin_num1 };
                std::cout << std::endl;
                std::cout << c << std::endl;
                std::cout << std::endl;
                break;
            }

        } while (true);

        break;


    case kShape::triangle:

        do
        {
            std::cout << "Please enter side lengths of triangle, separated by space:  ";
            std::cin >> cin_num1 >> cin_num2 >> cin_num3;

            if (std::cin.fail())
            {
                cin_num_exception();
            }

            else
            {
                try
                {
                    triangle t{ cin_num1, cin_num2, cin_num3 };
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

        break;

    }

}

void cin_shape(const std::string& str)
{

    kShape ks = std::move(stringToShape(str));

    switch (ks)
    {
    case kShape::rectangle:

        cin_num(ks);

        break;


    case kShape::square:

        cin_num(ks);

        break;


    case kShape::circle:

        cin_num(ks);

        break;


    case kShape::triangle:

        cin_num(ks);

        break;


    default:

        std::cout << "This isn't a shape (rectangle, square, circle, triangle)." << std::endl;
        std::cout << std::endl;

    }


}
