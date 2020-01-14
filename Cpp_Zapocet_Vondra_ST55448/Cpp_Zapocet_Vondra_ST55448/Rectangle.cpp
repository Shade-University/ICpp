#include "Rectangle.h"


std::string Rectangle::toString() const
{
	return "Rectangle{a=" + std::to_string(a) + ", b=" + std::to_string(b) + "}";

}
double Rectangle::calculatePerimeter() const
{
	return 2 * (a + b);
}
double Rectangle::calculateArea() const
{
	return a * b;
}

Rectangle* Rectangle::create(std::istream& stream)
{
	int a, b;
	stream >> a >> b;
	return new Rectangle(a, b);
}
