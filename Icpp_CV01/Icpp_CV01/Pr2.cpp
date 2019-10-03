#include <iostream>

using namespace std;

struct Trojuhelnik
{
	int a, b, c;
};

bool lzeSestrojit(Trojuhelnik trojuhelnik)
{
	return (trojuhelnik.a + trojuhelnik.b > trojuhelnik.c
		&& trojuhelnik.a + trojuhelnik.c > trojuhelnik.b
		&& trojuhelnik.b + trojuhelnik.c > trojuhelnik.a);
}
int spocitejObvod(Trojuhelnik trojuhelnik)
{
	return trojuhelnik.a + trojuhelnik.b + trojuhelnik.c;
}

int main() 
{
	Trojuhelnik trojuhelnik;
	cout << "Zadejte stranu a: ";
	cin >> trojuhelnik.a;
	cout << "Zadejte stranu b: ";
	cin >> trojuhelnik.b;
	cout << "Zadejte stranu c: ";
	cin >> trojuhelnik.c;

	if (lzeSestrojit(trojuhelnik)) {
		cout << "Lze sestrojit" << endl;
		cout << "Obvod: " << spocitejObvod(trojuhelnik);
	}
	else {
		cout << "Nelze sestrojit";
	}
}