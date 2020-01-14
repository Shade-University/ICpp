#include "Triangle.h"


std::string Triangle::toString() const
{
	return "Triangle{a=" + std::to_string(a) + ", b=" + std::to_string(b) + ", c=" + std::to_string(c) + "}";
}

double Triangle::calculatePerimeter() const
{
	return a + b + c;
}
double Triangle::calculateArea() const
{
	double s = (a + b + c) / 2;

	return sqrt(s * (s - a) * (s - b) * (s - c)); //Heronùv vzorec
}

Triangle* Triangle::create(std::istream& stream)
{
	int a, b, c;
	stream >> a >> b >> c;
	return new Triangle(a, b, c); 
}
