#include "MyLibrary.h"
#include <iostream>

void MyLibrary::sayHello() const
{
	std::cout << "Hello from LIB!" << std::endl;
}

void MyLibrary::sayBye() const
{
	std::cout << "Bye from LIB!" << std::endl;
}
