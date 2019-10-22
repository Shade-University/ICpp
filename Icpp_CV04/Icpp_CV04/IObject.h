#pragma once
#include <string>

class IObject
{
public:
	virtual std::string toString() const = 0;
};
