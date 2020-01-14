#pragma once
#include "Shape.h"
class Circle : public Shape
{
public:
	Circle(int rValue) : r(rValue) {};

	virtual std::string toString() const override;
	virtual double calculatePerimeter() const override;
	virtual double calculateArea() const override;

	static Circle* create(std::istream& stream);
private:
	int r;
};

