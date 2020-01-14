#ifndef ZPRAVAPORT_H
#define ZPRAVAPORT_H

#include "Zprava.h"

struct ASitovyPrvek;

struct ZpravaPort {
	Zprava* zprava;
	ASitovyPrvek* port;
	ZpravaPort() { }
	ZpravaPort(Zprava* zprava, ASitovyPrvek* port) : zprava(zprava), port(port) {
	}
};

#endif
