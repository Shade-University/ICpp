#pragma once
#include "Shape.h"
class Triangle : public Shape
{
public:
	Triangle(int aValue, int bValue, int cValue) :a(aValue), b(bValue), c(cValue) {};

	virtual std::string toString() const override;
	virtual double calculatePerimeter() const override;
	virtual double calculateArea() const override;

	static Triangle* create(std::istream& stream);
private:
	int a;
	int b;
	int c;
};

