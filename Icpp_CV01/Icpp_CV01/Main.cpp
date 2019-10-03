#include <iostream>

using namespace std;

struct Trojuhelnik
{
	int a, b, c;
};

bool lzeSestrojit(Trojuhelnik* trojuhelnik)
{
	return (trojuhelnik->a + trojuhelnik->b > trojuhelnik->c
		&& trojuhelnik->a + trojuhelnik->c > trojuhelnik->b
		&& trojuhelnik->b + trojuhelnik->c > trojuhelnik->a);
}
int spocitejObvod(Trojuhelnik trojuhelnik)
{
	return trojuhelnik.a + trojuhelnik.b + trojuhelnik.c;
}

int main()
{
	int pocetTrojuhelniku;
	cout << "Zadejte pocet trojuhelniku: ";
	cin >> pocetTrojuhelniku;
	cout << "----------------------------" << endl;

	Trojuhelnik* trojuhelniky = new Trojuhelnik[pocetTrojuhelniku];
	for (int i = 0; i < pocetTrojuhelniku; i++)
	{
		cout << "Trojuhelnik " << i + 1 << endl;
		cout << "-------------" << endl;
		cout << "Zadejte stranu a: ";
		cin >> trojuhelniky[i].a;
		cout << "Zadejte stranu b: ";
		cin >> trojuhelniky[i].b;
		cout << "Zadejte stranu c: ";
		cin >> trojuhelniky[i].c;
		cout << endl;

		if (lzeSestrojit(&trojuhelniky[i])) {
			cout << "Lze sestrojit" << endl;
			cout << "Obvod: " << spocitejObvod(trojuhelniky[i]) << endl;
		}
		else {
			cout << "Nelze sestrojit" << endl;
		}
		cout << endl;
	}

	delete[] trojuhelniky;
	
	cout << endl;
	cout << "Konec programu";
	cin.get(); cin.get();
}
