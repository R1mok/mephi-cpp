#include <iostream>
#include <cmath>
#include "../lab3b/BigInt.h"


using namespace Prog3b;
int main()
{
	long temp = 402;
	BigInt b(temp);
	const char* s = "402";
	BigInt c(s);
	BigInt a;
	a = b + c;
	a.increase();
	std::cout << a;
	return 0;
}