#pragma once

#include "IComparable.h"

class Time : public IComparable
{
private:
	int _hours;
	int _minutes;
	int _seconds;
public:
	Time(int hours, int minutes, int seconds)
	{
		_hours = hours;
		_minutes = minutes;
		_seconds = seconds;
	}
	virtual std::string toString() const;
	virtual int compareTo(IComparable* obj) const;
};

