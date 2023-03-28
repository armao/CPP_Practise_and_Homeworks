#include <iostream>
#include <iomanip>
#include <utility>
#include "shape.h"
#include <string>
#include <stdexcept>
#include "kShape.h"


int main(int argc, char* argv[])
{
    
    std::string cin_str;
    
    do
    {
        std::cout << "Please enter a shape(or enter \"close\" to end program):  ";
        std::cin >> cin_str;

        if (cin_str == "close" || cin_str == "Close" || cin_str == "CLOSE")
        {
            std::cout << std::endl << "bye bye!";
            break;
        }
        
        cin_shape(cin_str);
        
    } while (true);

    return 0;

}
