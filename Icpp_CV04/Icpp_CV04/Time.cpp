#include "Time.h"

std::string Time::toString() const
{
	return "Time: " + std::to_string(_hours) + ":"
		+ std::to_string(_minutes) + ":"
		+ std::to_string(_seconds);
}
int Time::compareTo(IComparable* object) const
{
	Time* obj = dynamic_cast<Time*>(object);
	int value = this->_hours * 3600 + this->_minutes * 60 + this->_seconds;
	int other_value = obj->_hours * 3600 + obj->_minutes * 60 + obj->_seconds;
	
	if (value == other_value) return 0;
	else if (value > other_value) return 1;
	else return -1;
}