#pragma once
#include "Osoba.h"
#include <exception>

namespace Model {
	using namespace Entity;

	class PrvekSeznam
	{
	public:
		PrvekSeznam(Osoba o, PrvekSeznam* dalsi)
		{
			this->o = o;
			this->dalsi = dalsi;
		}
		Osoba getOsoba() const { return o; }
		void setOsoba(Osoba o) { this->o = o; }
		PrvekSeznam* getDalsi() const { return dalsi; }
		void setDalsi(PrvekSeznam* o) { this->dalsi = o; }
	private:
		Osoba o;
		PrvekSeznam* dalsi;
	};

	class TelefonniSeznam
	{
	public:
		TelefonniSeznam();
		~TelefonniSeznam();
		void pridejOsobu(Osoba o);
		std::string najdiTelefon(std::string jmeno) const;
		std::string najdiTelefon(int id) const;
	private:
		PrvekSeznam* _zacatek;
	};
	
}

