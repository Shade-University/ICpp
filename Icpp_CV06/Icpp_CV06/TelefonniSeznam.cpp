#include "TelefonniSeznam.h"

namespace Model {
	TelefonniSeznam::TelefonniSeznam() { _zacatek = nullptr; _konec = nullptr; }
	TelefonniSeznam::~TelefonniSeznam()
	{
		PrvekSeznam* tmp = _zacatek;
		while (tmp != nullptr)
		{
			PrvekSeznam* dalsi = tmp->getDalsi();
			delete tmp;
			tmp = dalsi;
		}

		_zacatek = nullptr;
		_konec = nullptr;
	}
	void TelefonniSeznam::pridejOsobu(Osoba o)
	{
		if (_zacatek == nullptr)
		{
			_zacatek = new PrvekSeznam(o, nullptr);
			_konec = _zacatek;
		}
		else
		{
			_konec->setDalsi(new PrvekSeznam(o, nullptr));
			_konec = _konec->getDalsi();
		}
	}
	std::string TelefonniSeznam::najdiTelefon(std::string jmeno) const
	{
		if (jmeno.empty())
			throw std::invalid_argument("Jmeno je prazdne");
		if (_zacatek == nullptr)
			throw std::out_of_range("Telefonni seznam je prazdny");

		if (_zacatek->getOsoba().getJmeno()._Equal(jmeno))
			return _zacatek->getOsoba().getTelefon();

		PrvekSeznam* tmp = _zacatek;
		while (tmp->getDalsi() != nullptr)
		{
			tmp = tmp->getDalsi();
			if (tmp->getOsoba().getJmeno()._Equal(jmeno))
				return tmp->getOsoba().getTelefon();

		}

		throw std::exception("Nenalezeno");
	}
	std::string TelefonniSeznam::najdiTelefon(int id) const
	{
		if (id < 0)
			throw std::invalid_argument("Id je zaporne");

		if (_zacatek->getOsoba().getId() == id)
			return _zacatek->getOsoba().getTelefon();

		PrvekSeznam* tmp = _zacatek;
		while (tmp->getDalsi() != nullptr)
		{
			tmp = tmp->getDalsi();
			if (tmp->getOsoba().getId() == id)
				return tmp->getOsoba().getTelefon();
		}

		throw std::exception("Nenalezeno");
	}
}
