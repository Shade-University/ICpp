#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

#include "PipeComponent.h"
#include "Pipe.h"


IPipe* loadPipe(std::string path)
{
	std::ifstream file;
	file.open(path);
	if (!file) {
		std::cout << "Unable to open file";
		std::cin.get();
		exit(1);
	}

	std::string buffer;
	if (!std::getline(file, buffer))
		throw std::exception("Bad file format");

	int size = stoi(buffer);
	std::vector<APipeComponent*> vect;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char c = file.get();
			if (c == '\n')
				break;
			vect.push_back(new PipeComponent(i, j, c));
		}
	}
	file.close();

	return new Pipe(vect);
}
int main()
{
	IPipe* pipe1 = loadPipe("pipe1.txt");
	std::cout << pipe1->IsPipeValid() << std::endl;
	IPipe* pipe2 = loadPipe("pipe2.txt");
	std::cout << pipe2->IsPipeValid() << std::endl;
	IPipe* pipe3 = loadPipe("pipe3.txt");
	std::cout << pipe3->IsPipeValid() << std::endl;
	IPipe* pipe4 = loadPipe("pipe4.txt");
	std::cout << pipe4->IsPipeValid() << std::endl;
	IPipe* pipe5 = loadPipe("pipe5.txt");
	std::cout << pipe5->IsPipeValid() << std::endl;
	IPipe* pipe6 = loadPipe("pipe6.txt");
	std::cout << pipe6->IsPipeValid() << std::endl;
	IPipe* pipe7 = loadPipe("pipe7.txt");
	std::cout << pipe7->IsPipeValid() << std::endl;
	IPipe* pipe8 = loadPipe("pipe8.txt");
	std::cout << pipe8->IsPipeValid() << std::endl;

	std::cin.get();
}