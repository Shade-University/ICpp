#pragma once
class Uctenka
{
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	int GetCisloUctenky() const
	{
		return this->cisloUctenky;
	}
	void SetCisloUctenky(int cisloUctenky)
	{
		this->cisloUctenky = cisloUctenky;
	}

	double GetCastka() const
	{
		return this->castka;
	}
	void SetCastka(double castka)
	{
		this->castka = castka;
	}

	double GetDph() const
	{
		return this->dph;
	}
	void SetDph(double dph)
	{
		this->dph = dph;
	}
};

