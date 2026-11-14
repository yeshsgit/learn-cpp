#include <iostream>


int doubleNumber(int num)
{
	return 2 * num;
}


int main()
{
	std::cout << "Enter an integer: ";

	int num {};
	std::cin >> num;

	std::cout << "Double " << num << " is " << doubleNumber(num) << '\n';

	return 0;
}
