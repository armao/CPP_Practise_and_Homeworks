#include <iostream>
#include <iomanip>
#pragma once
#include <string>

class shape
{
public:
	virtual ~shape() = default;
	virtual float area() const = 0;
	virtual float perimeter() const = 0;
	virtual float circumference() const = 0;
	virtual std::ostream& print(std::ostream& os) const = 0;

};

class rectangle : public shape
{
public:
	rectangle();
	rectangle(float width, float height);
	float area() const override;
	float perimeter() const override;
	float circumference() const override;
	float width() const;
	float height() const;
	std::ostream& print(std::ostream& ostream) const override;
	

private:
	float m_width;
	float m_height;

};

class square : public rectangle
{
public:
	square(float sideLength);
	float area() const override;
	float perimeter() const override;
	float circumference() const override;
	float sideLength() const;
	std::ostream& print(std::ostream& ostream) const override;
	

private:
	float m_sideLength;

};

class circle : public shape
{
public:
	circle(float radius);
	float area() const override;
	float circumference() const override;
	float perimeter() const override;
	float raduius() const;
	std::ostream& print(std::ostream& ostream) const override;

	

private:
	float m_radius;
	float m_pi = 3.14159f;

};

class triangle : public shape
{
public:
	triangle(float sideOne, float sideTwo, float sideThree);
	float area() const override;
	float perimeter() const override;
	float circumference() const override;
	float sideOne() const;
	float sideTwo() const;
	float sideThree() const;
	std::ostream& print(std::ostream& ostream) const override;

private:
	float m_sideOne;
	float m_sideTwo;
	float m_sideThree;

};

std::ostream& operator<<(std::ostream& ostream, const shape& a_shape);
std::ostream& operator<<(std::ostream& ostream, const rectangle a_srectangle);
std::ostream& operator<<(std::ostream& ostream, const square a_square);
std::ostream& operator<<(std::ostream& ostream, const circle a_circle);
std::ostream& operator<<(std::ostream& ostream, const triangle a_triangle);



