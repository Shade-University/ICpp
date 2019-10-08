#include "Pokladna.h"


#define POLE_VELIKOST	10

int Pokladna::CITAC_ID = 1000;
	Pokladna::Pokladna() 
	{
		uctenky = new Uctenka[POLE_VELIKOST];
		pocetVydanychUctenek = 0;
	}
	Pokladna::~Pokladna()
	{
		delete[] uctenky;
	}

	void Pokladna::VystavUctenku(double castka, double dph)
	{
		if (pocetVydanychUctenek + 1 >= POLE_VELIKOST)
			throw std::out_of_range("blah");

		uctenky[pocetVydanychUctenek].SetCisloUctenky(CITAC_ID++);
		uctenky[pocetVydanychUctenek].SetCastka(castka);
		uctenky[pocetVydanychUctenek].SetDph(dph);
		pocetVydanychUctenek++;
	}
	Uctenka& Pokladna::DejUctenku(int cisloUctenky)
	{
		for (int i = 0; i < pocetVydanychUctenek; i++)
		{
			if (uctenky[i].GetCisloUctenky() == cisloUctenky)
			{
				return uctenky[i];
			}
		}

		return uctenky[0];
	}
	double Pokladna::DejCastku() const
	{
		double castka = 0;
		for (int i = 0; i < pocetVydanychUctenek; i++)
		{
			castka += uctenky[i].GetCastka();
		}
		return castka;
	}
	double Pokladna::DejCastkuVcDph() const
	{
		double castka = 0;
		for (int i = 0; i < pocetVydanychUctenek; i++)
		{
			castka += uctenky[i].GetCastka() * (1 + uctenky[i].GetDph());
		}
		return castka;
	}
