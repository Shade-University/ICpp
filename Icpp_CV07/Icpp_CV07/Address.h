#pragma once
#include <iostream>
struct Address
{
public:
	Address() {}
	Address(std::string street, std::string town, int psc)
	{
		this->_street = street;
		this->_town = town;
		this->_psc = psc;
	}
	friend std::ostream& operator << (std::ostream& out, const Address& a)
	{
		return out << a._street << " " << a._town << " " << a._psc;
	}
	friend std::istream& operator >> (std::istream& in, Address& a)
	{
		return in >> a._street >> a._town >> a._psc;
	}
private:
	std::string _street;
	std::string _town;
	int _psc;
};