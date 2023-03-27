#include <iostream>
#include <iomanip>
#include <utility>
#include "shape.h"
#include <string>
#include <stdexcept>

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

void cin_num_exception()
{
    std::cout << "Have to enter the number." << std::endl;
    std::cout << "Please retry again." << std::endl;
    std::string s;
    std::cin.clear();
    std::getline(std::cin, s, '\n');
}

int main(int argc, char* argv[])
{
    bool notyet = true;
    std::string str;
    float num1 = 0.f;
    float num2 = 0.f;
    float num3 = 0.f;
    
    do
    {
        std::cout << "Please enter a shape(or enter \"close\" to end program):  ";
        std::cin >> str;
        kShape ks = std::move(stringToShape(str));

        switch (ks)
        {
            case kShape::rectangle:
            {
                do
                {
                    std::cout << "Please enter width and height, separated by space:  ";
                    std::cin >> num1 >> num2;
                    if (std::cin.fail())
                    {
                        cin_num_exception();
                    }
                    else
                    {
                        rectangle r{ num1, num2 };
                        std::cout << r << std::endl;
                        break;
                    }

                } while (true);
                
                break;

            }

            case kShape::square:
            {
                do 
                {
                    std::cout << "Please enter side length:  ";
                    std::cin >> num1;
                    if (std::cin.fail())
                    {
                        cin_num_exception();
                    }
                    else
                    {
                        square sq{ num1 };
                        std::cout << sq << std::endl;
                        break;
                    }

                } while (true);

                break;

            }

            case kShape::circle:
            {
                do {
                    std::cout << "Please enter radius:  ";
                    std::cin >> num1;
                    if (std::cin.fail())
                    {
                        cin_num_exception();
                    }
                    else
                    {
                        circle c{ num1 };
                        std::cout << c << std::endl;
                        break;
                    }
                } while (true);

                break;

            }

            case kShape::triangle:
            {
                do 
                {
                    std::cout << "Please enter side lengths of triangle, separated by space:  ";
                    std::cin >> num1 >> num2 >> num3;
                    if (std::cin.fail())
                    {
                        cin_num_exception();
                    }
                    else
                    {
                        try 
                        {
                            triangle t{ num1, num2, num3 };
                            std::cout << t << std::endl;
                            break;
                        }
                        catch(const std::invalid_argument& e)
                        {
                            std::cout << e.what() << std::endl;
                        }
                    }

                } while (true);

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
