#pragma once
#include <stdlib.h>
#include <stdexcept>
#include "Uctenka.h"

class Pokladna
{
private:
	static int CITAC_ID;
	Uctenka* uctenky;
	int pocetVydanychUctenek;
public:
	Pokladna();
	~Pokladna();
	void VystavUctenku(double castka, double dph);
	Uctenka& DejUctenku(int cisloUctenky);
	double DejCastku() const;
	double DejCastkuVcDph() const;
};

