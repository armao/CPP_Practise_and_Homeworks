#pragma once

#include <string>

enum class kShape
{
    rectangle,
    square,
    circle,
    triangle,
    exception,
};

kShape stringToShape(const std::string& str);

void cin_num_exception();
void cin_num(const kShape& ks);
void cin_shape(const std::string& str);
