#ifndef SIT_H
#define SIT_H

#include "ASitovyPrvek.h"
class Sit
{

static int idZpravy;
static int DejNoveId();

private:
	Fronta<ASitovyPrvek*> sitovePrvky;
public:
	void Pripoj(ASitovyPrvek* sitovyPrvek)
	{
		sitovePrvky.Vloz(sitovyPrvek);
	}
	void ProvadejVse()
	{
		//TODO sitovePrvky.ZpracujPrvky();
	}
};

#endif

