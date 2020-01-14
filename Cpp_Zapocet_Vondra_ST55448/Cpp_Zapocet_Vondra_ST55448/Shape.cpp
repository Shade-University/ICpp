#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

Shape* Shape::create(std::istream& stream)
{
	std::string name;
	stream >> name;

	if (name._Equal("circle"))
	{
		return Circle::create(stream);
		/*int r;
		stream >> r;
		return new Circle(r); */
	}
	else if (name._Equal("rectangle"))
	{
		return Rectangle::create(stream);
		/*int a, b;
		stream >> a >> b;
		return new Rectangle(a, b); */
	}
	else if (name._Equal("square"))
	{
		return Square::create(stream);
		/*int a;
		stream >> a;
		return new Square(a); */
	}
	else if (name._Equal("triangle"))
	{
		return Triangle::create(stream);
		/*int a, b, c;
		stream >> a >> b >> c;
		return new Triangle(a, b, c); */
	}
	else
	{
		throw "Bad format";
	}

}
