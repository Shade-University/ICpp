#ifndef HUB_H
#define HUB_H

#include "ASitovyPrvek.h"
#include <stdexcept>

struct ZpravaPort;
struct Hub :
	public ASitovyPrvek
{
private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta<Zprava*> zpracovaneZpravy;
	int pocetPripojenychPrvku = 0;
public:
	Hub(int maxPrvku)
	{
		maximumPripojenychPrvku = maxPrvku;

		for (int i = 0; i < maximumPripojenychPrvku; i++)
		{
			pripojenePrvky[i] = nullptr;
		}
	}
	void Pripoj(ASitovyPrvek* sitovyPrvek) const override;
	void Provadej() const override;
private:
	void virtual ZpracujPrichoziZpravu(ZpravaPort zp) const override;
};
#endif

