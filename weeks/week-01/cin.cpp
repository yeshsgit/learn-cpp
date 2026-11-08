#include <iostream>


int main()
{
    std::cout << "Enter a number: ";

    int x {}; // value initialisation - the best practice

    std::cin >> x;

    std::cout << "Ha! You entered " << x << '\n';

    return 0;
}
