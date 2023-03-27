#include <iostream>
#include <iomanip>
#include "shape.h"
#include <utility>
#include <math.h>
#include <string>

rectangle::rectangle(float width, float height)
:m_width(std::move(width))
,m_height(std::move(height))
{
}

float rectangle::area() const
{
	return m_width * m_height;
}

float rectangle::perimeter() const
{
	return (m_width * 2) + (m_height * 2);
}

float rectangle::circumference() const
{
	return rectangle::perimeter();
}

float rectangle::width() const
{
	return m_width;
}

float rectangle::height() const
{
	return m_height;
}

std::ostream& rectangle::print(std::ostream& ostream) const
{
	return ostream << *this;
}

//

square::square(float sideLength)
:m_sideLength(std::move(sideLength))
,rectangle::rectangle(sideLength, sideLength)
{
}

float square::sideLength() const
{
	return m_sideLength;
}

std::ostream& square::print(std::ostream& ostream) const
{
	return ostream << *this;
}

//

circle::circle(float radius)
:m_radius(std::move(radius))
{
}

float circle::area() const
{
	return m_radius * m_radius * m_pi;
}

float circle::circumference() const
{
	return (m_radius * 2) * m_pi;
}

float circle::perimeter() const
{
	return circle::circumference();
}

float circle::raduius()const
{
	return m_radius;
}

std::ostream& circle::print(std::ostream& ostream) const
{
	return ostream << *this;
}

//

triangle::triangle(float sideOne, float sideTwo, float sideThree)
	:m_sideOne(std::move(sideOne))
	,m_sideTwo(std::move(sideTwo))
	,m_sideThree(std::move(sideThree))

{
		if (sideOne + sideTwo <= sideThree ||
			sideOne + sideThree <= sideTwo ||
			sideTwo + sideThree <= sideOne
			)
		{
			std::cout << "三個邊為"
				<< " ( " << sideOne
				<< " , " << sideTwo
				<< " , " << sideThree
				<< " ) " << "的線段無法成立三角形" << std::endl;
		}
}

float triangle::area() const
{
	float s = ((m_sideOne + m_sideTwo + m_sideThree) / 2);
	return
		sqrt((s * (s - m_sideOne) * (s - m_sideTwo) * (s - m_sideThree)));
}

float triangle::perimeter() const
{
	return m_sideOne + m_sideTwo + m_sideThree;
}

float triangle::circumference() const
{
	return triangle::perimeter();
}

float triangle::sideOne() const
{
	return m_sideOne;
}

float triangle::sideTwo() const
{
	return m_sideTwo;
}

float triangle::sideThree() const
{
	return m_sideThree;
}

std::ostream& triangle::print(std::ostream& ostream) const
{
	return ostream << *this;
}

//

std::ostream& operator<<(std::ostream& ostream, const shape& shapeRef)
{
	return shapeRef.print(ostream);
}

// rectangle(w: XXX, h: XXX, area: XXX, perimeter: XXX)
std::ostream& operator<<(std::ostream& ostream, const rectangle a_rectangle)
{
	return ostream
		<< "rectangle(w: " << a_rectangle.width()
		<< ", h: " << a_rectangle.height()
		<< ", area: " << a_rectangle.area()
		<< ", perimeter: " << a_rectangle.perimeter()
		<< ")";
}

// square(s: XXX, area: XXX, perimeter: XXX)
std::ostream& operator<<(std::ostream& ostream, const square a_square)
{
	return ostream
		<< "square(s: " << a_square.sideLength()
		<< ", area: " << a_square.area()
		<< ", perimeter: " << a_square.perimeter()
		<< ")";
}

// circle(r: XXX, area: XXX, circumference: XXX)
std::ostream& operator<<(std::ostream& ostream, const circle a_circle)
{
	return ostream
		<< "circle(r: " << a_circle.raduius()
		<< ", area: " << a_circle.area()
		<< ", circumference: " << a_circle.circumference()
		<< ")";
}

// triangle(1: XXX, 2: XXX, 3: XXX, area: XXX, perimeter: XXX)
std::ostream& operator<<(std::ostream& ostream, const triangle a_triangle)
{
	return ostream
		<< "triangle(s1: " << a_triangle.sideOne()
		<< ", s2: " << a_triangle.sideTwo()
		<< ", s3: " << a_triangle.sideThree()
		<< ", area: " << a_triangle.area()
		<< ", perimeter: " << a_triangle.perimeter()
		<< ")";
}
