#include <iostream>
#include "TelefonniSeznam.h"

int main()
{
	Model::TelefonniSeznam seznam;

	seznam.pridejOsobu(Entity::Osoba("Jmeno1", "Tel1", 1));
	seznam.pridejOsobu(Entity::Osoba("Jmeno2", "Tel2", 2));
	seznam.pridejOsobu(Entity::Osoba("Jmeno3", "Tel3", 3));

	std::cout << seznam.najdiTelefon("Jmeno1") << std::endl;
	std::cout << seznam.najdiTelefon("Jmeno2") << std::endl;
	std::cout << seznam.najdiTelefon("Jmeno3") << std::endl;

	std::cout << seznam.najdiTelefon(1) << std::endl;
	std::cout << seznam.najdiTelefon(2) << std::endl;
	std::cout << seznam.najdiTelefon(3) << std::endl;


	std::cin.get();

}
