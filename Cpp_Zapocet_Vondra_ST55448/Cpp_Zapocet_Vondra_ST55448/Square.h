#pragma once
#include "Shape.h"
class Square : public Shape
{
public:
	Square(int aValue) : a(aValue) {};

	virtual std::string toString() const override;
	virtual double calculatePerimeter() const override;
	virtual double calculateArea() const override;

	static Square* create(std::istream& stream);
private:
	int a;
};

