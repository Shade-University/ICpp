#pragma once
#include <iostream>
namespace Entity {
	class Osoba
	{
	public:
		Osoba() {};
		Osoba(std::string jmeno, std::string telefon, int id)
		{
			this->jmeno = jmeno;
			this->telefon = telefon;
			this->id = id;
		}
		void setJmeno(std::string jmeno) { this->jmeno = jmeno; }
		void setTelefon(std::string telefon) { this->telefon = telefon; }
		void setId(int id) { this->id = id; }

		std::string getJmeno() const { return jmeno; }
		std::string getTelefon() const { return telefon; }
		int getId() const { return id; }

	private:
		std::string jmeno;
		std::string telefon;
		int id;
	};
}

