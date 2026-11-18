#include "io.h"
#include <iostream>


int readNumber()
{
	std::cout << "Enter an integer: ";
	int num {};
	std::cin >> num;
	return num;
}


void writeAnswer(int answer)
{
	std::cout << "The answer is " << answer << '\n';
}
