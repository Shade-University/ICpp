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
	//TODO Nem��eme dostat zpr�vu z fronty

}

void Hub::ZpracujPrichoziZpravu(ZpravaPort zp) const
{
	//TODO
}
