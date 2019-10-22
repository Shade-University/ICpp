#include <iostream>
#include <algorithm>
#include "Time.h"


#define ARRAY_SIZE	10

bool compare(IComparable* l, IComparable* r)
{
	return l->compareTo(r) < 0;
}

void sortArray(IComparable** arr, int size)
{
	std::sort(arr, arr + size, compare);
}

int main()
{
	std::cout << "Nesetridene pole: " << std::endl;

	IComparable** arr = new IComparable * [ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = new Time(rand() % 24, rand() % 60, rand() % 60);
		std::cout << arr[i]->toString() << std::endl;
	}

	sortArray(arr, ARRAY_SIZE);

	std::cout << std::endl << "Setridene pole: " << std::endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << arr[i]->toString() << std::endl;
	}

	delete[] arr;
	

	std::cin.get();
}
