#include "Circle.h"



std::string Circle::toString() const
{
	return "Circle{r=" + std::to_string(r) + "}";
}
double Circle::calculatePerimeter() const
{
	return 2 * 3.14 * r;
}
double Circle::calculateArea() const
{
	return 3.14 * r * r;
}

Circle* Circle::create(std::istream& stream)
{
	int r;
	stream >> r;
	return new Circle(r);
}

