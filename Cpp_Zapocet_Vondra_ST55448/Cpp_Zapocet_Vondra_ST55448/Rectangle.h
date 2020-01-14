#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(int aValue, int bValue) :a(aValue), b(bValue) {};

	virtual std::string toString() const override;
	virtual double calculatePerimeter() const override;
	virtual double calculateArea() const override;

	static Rectangle* create(std::istream& stream);
private:
	int a;
	int b;
};

