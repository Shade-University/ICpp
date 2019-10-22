#pragma once

#include "IObject.h"

class IComparable : public IObject
{
public:
	virtual int compareTo(IComparable* obj) const = 0;
};
