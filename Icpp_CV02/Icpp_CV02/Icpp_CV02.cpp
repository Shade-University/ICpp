#include <iostream>
#include "Pokladna.h"

using namespace std;

int main()
{
	Pokladna pokladna;
	pokladna.VystavUctenku(100, 20);
	pokladna.VystavUctenku(200, 10);
	pokladna.VystavUctenku(300, 30);
    
	cout << "Castka vsech uctenek bez dph: " << pokladna.DejCastku() << endl;
	cout << "Castka vsech uctenek s dph: " << pokladna.DejCastkuVcDph() << endl;
	
	Uctenka& uctenka1 = pokladna.DejUctenku(1000);
	Uctenka& uctenka2 = pokladna.DejUctenku(1001);
	Uctenka& uctenka3 = pokladna.DejUctenku(1002);

	uctenka1.SetCastka(1000);
	uctenka2.SetCastka(2000);
	uctenka3.SetCastka(3000);

	cout << endl << "Po zmene hodnot" << endl;
	cout << "Castka vsech uctenek bez dph: " << pokladna.DejCastku() << endl;
	cout << "Castka vsech uctenek s dph: " << pokladna.DejCastkuVcDph() << endl;


	
	cin.get();
}
