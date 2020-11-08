#include <iostream>
#include <cmath>
#include "../lab3c/BigInt.h"


using namespace Prog3c;
int main()
{
	long t = 3213;
	BigInt a(t);
	const char* str = "523";
	BigInt b(str);
	std::cout << a - b;
	return 0;
}