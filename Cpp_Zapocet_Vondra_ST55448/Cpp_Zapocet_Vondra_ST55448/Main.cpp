#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Shape.h"

void dealloc(Shape** shapes, int count)
{
	for (int i = 0; i < count; i++)
	{
		delete shapes[i];
	}
	delete[] shapes;

}
int main()
{
	int count;
	Shape** shapes = nullptr;
	std::ifstream file("shapesinput.txt");

	if (file.is_open()) {

		file >> count;
		shapes = new Shape*[count];

		std::string line;
		int i = 0;
		std::getline(file, line); //Skip first line
		while (std::getline(file, line))
		{
			std::istringstream iss(line);
			shapes[i] = Shape::create(iss);
			std::cout << shapes[i]->toString() << " - Area: " << shapes[i]->calculateArea() << ", perimeter: " << shapes[i]->calculatePerimeter() << std::endl;
			i++;
		}
		dealloc(shapes, count);
		file.close();
	}
	else {
		throw "File not found";
	}	

	std::cin.get();
}