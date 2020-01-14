#pragma once
#include <string>

class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};
	virtual std::string toString() const = 0;
	virtual double calculatePerimeter() const  = 0;
	virtual double calculateArea() const = 0;

	static Shape* create(std::istream& stream);
};