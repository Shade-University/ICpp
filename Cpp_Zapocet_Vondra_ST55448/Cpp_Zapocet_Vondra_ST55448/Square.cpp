#include "Square.h"

std::string Square::toString() const
{
	return "Square{a=" + std::to_string(a) + "}";

}
double Square::calculatePerimeter() const
{
	return 4 * a;
}
double Square::calculateArea() const
{
	return a * a;
}

Square* Square::create(std::istream& stream)
{
	int a;
	stream >> a;
	return new Square(a);
}
