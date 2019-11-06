#include "MyLibrary.h"
#include <iostream>

int main(int argc, char* argv) {

	MyLibrary lib;
	lib.sayHello();
	lib.sayBye();
	std::cin.get();
	return 0;
}