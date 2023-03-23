#include <iostream>
#include <iomanip>
#include <utility>
#include "shape.h"
#include <string>

int main(int argc, char* argv[])
{
    rectangle r{ 5, 3 };
    square sq{ 10 };
    circle c{ 3 };
    triangle t{ 3, 4, 5 };
    triangle t2{ 1,1, 0};

    const shape& s = r;
    std::cout << t.area() << std::endl;
    std::cout << s.area() << std::endl;
    std::cout << s.circumference() << std::endl;
    std::cout << s.perimeter() << std::endl;

    // rectangle(w: XXX, h:XXX, area: XXX, perimeter: XXX)
    // square(s: XXX, area: XXX, perimeter: XXX)
    // circle(r: XXX, area: XXX, circumference: XXX)
    // triangle(???????, area: XXX, perimeter: XXX)
    std::cout << r << std::endl;
    std::cout << sq << std::endl;
    std::cout << c << std::endl;
    std::cout << t << std::endl;
    std::cout << s << std::endl;

    return 0;
}
