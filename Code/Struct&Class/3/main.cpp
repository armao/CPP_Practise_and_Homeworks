#include <iostream>
#include <iomanip>
#include <utility>
#include "family.h"
#include "human.h"

int main(int argc, char* argv[])
{
    family f;

    f.add_member(human{ "Mona" });

    const human dada{ "Dada" };
    f.add_member(dada);

    human xiao{ "Xiao Xiao" };
    f.add_member(std::move(xiao));
    
    f.print();
    
    // Dada
    std::cout << dada << std::endl;
    std::cout << dada.name_length() << std::endl;
    // Xiao Xiao
    std::cout << f.longest_name_member() << std::endl;

    // true
    std::cout << std::boolalpha << f.has_member_with_name("Mona") << std::endl;
    // false
    std::cout << std::boolalpha << f.has_member_with_name("Cookie") << std::endl;

    return 0;
}
