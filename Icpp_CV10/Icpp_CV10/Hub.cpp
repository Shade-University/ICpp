#include "Hub.h"

void Hub::Pripoj(ASitovyPrvek* sitovyPrvek) const
{
	if (pocetPripojenychPrvku == maximumPripojenychPrvku) {
		throw new std::out_of_range("Pocet prvku dosahl maxima.");
	}
	this->pripojenePrvky[pocetPripojenychPrvku] = sitovyPrvek;
	++sitovyPrvek;
}

void Hub::Provadej() const 
{
	if (zpracovaneZpravy.JePrazdna()) return;
	//TODO Nemùžeme dostat zprávu z fronty

}

void Hub::ZpracujPrichoziZpravu(ZpravaPort zp) const
{
	//TODO
}
