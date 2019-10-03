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
bool lzeSestrojit(int a, int b, int c)
{
	return (a + b > c && a + c > b && b + c > a);
}
int spocitejObvod(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	int a, b, c;
    cout << "Zadejte stranu a: ";
	cin >> a;
	cout << "Zadejte stranu b: ";
	cin >> b;
	cout << "Zadejte stranu c: ";
	cin >> c;

	cout << "Trojuhelnik: " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	if (lzeSestrojit(a, b, c)) {
		cout << "Lze sestrojit" << endl;
		cout << "Obvod: " << spocitejObvod(a, b, c);
	}
	else {
		cout << "Nelze sestrojit";
	}

	cin.get(); cin.get();
}
