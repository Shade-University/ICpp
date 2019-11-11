#include <iostream>
#include <fstream>
#include "Person.h"
#include <string>

#define ARR_SIZE	3

void save(std::string location, Person* arr, int arrCount)
{
	std::ofstream output(location);
	for (int i = 0; i < arrCount; i++)
	{
		output << arr[i] << std::endl;
	}
	output.close();
}
Person* load(std::string location)
{
	int countLines = 0;
	std::ifstream input(location);

	std::string tempLine;
	while (std::getline(input, tempLine))
		countLines++;

	input.clear();
	input.seekg(0, std::ios::beg);

	Person* arr = new Person[countLines];
	for (int i = 0; i < countLines; i++)
	{
		Person p;
		input >> p;
		arr[i] = p;
	}

	input.close();

	return arr;

}

void save_binary(std::string location, const Person* arr, int arrCount)
{
	std::ofstream output(location, std::ios::out | std::ios::binary);
	output.write((char*)&arr, sizeof(arr));
	output.close();
}

Person* load_binary(std::string location)
{
	int countLines = 0;
	std::ifstream input(location, std::ios::in | std::ios::binary);

	std::string tempLine;
	while (std::getline(input, tempLine))
		countLines++;

	input.clear();
	input.seekg(0, std::ios::beg);

	Person* arr = new Person[countLines];
	input.read((char*)&arr, sizeof(arr));

	input.close();

	return arr;

}

void printArray(Person* arr, int arrCount)
{
	for (int i = 0; i < arrCount; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
int main()
{
	Person* arr = new Person[ARR_SIZE]{
		{"name1", "lastname1", Address("street1", "town1", 1), Date(1,1,1)},
		{"name2", "lastname2", Address("street2", "town2", 2), Date(2,2,2)},
		{"name3", "lastname3", Address("street3", "town3", 3), Date(3,3,3)}
	};

	save("data.txt", arr, ARR_SIZE);
	Person* loadedData = load("data.txt");
	printArray(loadedData, ARR_SIZE);

	std::cout << std::endl;

	save_binary("data.bin", arr, ARR_SIZE);
	Person* loadedData_binary = load_binary("data.bin");
	printArray(loadedData_binary, ARR_SIZE);


	delete[] arr;
	delete[] loadedData;
	//delete[] loadedData_binary; loadedData_binary == arr	


	std::cin.get();
}