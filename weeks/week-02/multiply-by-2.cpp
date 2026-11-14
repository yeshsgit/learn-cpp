/*
Program description:

Asks user to enter an integer.
Waits for them to input an integer.
Then tells them what 2 times the number is.

e.g:

Enter an integer: 4
Double that number is: 8
*/

#include <iostream>


int main()
{
	int temp {};
	
	std::cout << "Enter an integer: ";

	std::cin >> temp;

	// Not quite a multiply by 2 program anymore and also
	// doesn't match the program spec completely after changes
	// for the quiz question.
	std::cout << "Double " << temp << " is: " << 2 * temp << '\n';
	std::cout << "Triple " << temp << " is: " << 3 * temp << '\n';

	return 0;
}

