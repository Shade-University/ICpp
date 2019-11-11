#pragma once

#include <iostream>
#include "Address.h"
#include "Date.h"

struct Person
{
public:
	Person() {}
	Person(std::string firstName, std::string lastName, Address address, Date dateOfBirth)
		: _address(address), _dateOfBirth(dateOfBirth), _firstName(firstName), _lastName(lastName) 
	{}
	friend std::ostream& operator << (std::ostream& out, const Person& p)
	{
		return out << p._firstName << " " << p._lastName << " " << p._address << " " << p._dateOfBirth;
	}
	friend std::istream& operator >> (std::istream& in, Person& p)
	{
		return in >> p._firstName >> p._lastName >> p._address >> p._dateOfBirth;
	}
private:
	std::string _firstName;
	std::string _lastName;
	Address _address;
	Date _dateOfBirth;
};