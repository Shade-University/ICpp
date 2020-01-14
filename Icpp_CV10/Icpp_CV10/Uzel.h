#ifndef UZEL_H
#define UZEL_H


#include "ASitovyPrvek.h"
#include "Zprava.h"
struct Uzel :
	public ASitovyPrvek
{
private:
	std::string adresa;
	Fronta<Zprava*> odchoziZpravy;
	ASitovyPrvek* pripojenyPrvek;
	void zpracujPrichoziZpravu(ZpravaPort zpravaPort);

public:
	void Pripoj(ASitovyPrvek* sitovyPrvek) const override;
	void Provadej() const override;
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);
};

#endif

