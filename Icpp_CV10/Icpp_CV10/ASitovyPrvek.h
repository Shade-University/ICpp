#ifndef ASITOVYPRVEK_H
#define ASITOVYPRVEK_H

#include "Fronta.h"
#include "Zprava.h"
#include "ZpravaPort.h"


struct ZpravaPort;
struct ASitovyPrvek
{

protected:
	Fronta<ZpravaPort> prichozyZpravy;
	void virtual ZpracujPrichoziZpravu(ZpravaPort zp) const = 0;

public:
	void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	void virtual Provadej() const = 0;
	void virtual Pripoj(ASitovyPrvek* sitovyPrvek) const = 0;

};

#endif