/*
Program reads two integers from the user,
adds them,
and then outputs the answer.

Uses 3 functions:
int readNumber() to get and return one integer from user
void writeAnswer(int answer) to output the answer
int main()
*/


#include "io.h"
#include <iostream>


int main()
{
	int num1 {readNumber()};
	int num2 {readNumber()};

	writeAnswer(num1 + num2);

	return 0;
}

