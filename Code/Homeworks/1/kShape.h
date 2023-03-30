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

void cin_num_rectangle();
void cin_num_square();
void cin_num_circle();
void cin_num_circle();

void cin_shape_switcherV1(const std::string& str);
void cin_shape_switcherV2(const std::string& str);
