#include <iostream>


int main()
{
	int x;

	// testing the return value of assignment
	// Testing showed that the assignment returned 5
	std::cout << "Checking return value of assigning 5 to x\n";
	std::cout << (x = 5) << '\n';

	std::cout << '\n';

	// testing the return value of insertion into std::cout
	std::cout << "Checking return value if std::cout << x "
				 "which contains the value 5\n";
	char y[] = "lskdjfals;kjdf;alskjdf;alksjdf;alskjdflskafj;askldf";
	&y = (std::cout << x);
	// So.. I wasn't able to get the return value of the assignment
	// stored into my character array.. not sure what exactly is causing the issue still
	std::cout << y << '\n';
	

	return 0;
}
