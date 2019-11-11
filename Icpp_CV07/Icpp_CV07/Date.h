#pragma once
#include <iostream>

struct Date
{
public:
	Date() {}
	Date(int day, int month, int year)
	{
		this->_day = day;
		this->_month = month;
		this->_year = year;
	}
	friend std::ostream& operator << (std::ostream& out, const Date& d)
	{
		return out << d._day << " " << d._month << " " << d._year;
	}
	friend std::istream& operator >> (std::istream& in, Date& d)
	{
		return in >> d._day >> d._month >> d._year;
	}
private:
	int _day;
	int _month;
	int _year;
};
