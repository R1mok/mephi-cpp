#include <iostream>
#include <cmath>
#include "..//BigInt.h"


using namespace Prog3a;
int main()
{
	BigInt a;
	long temp = -302;
	BigInt b(temp);
	const char* s = "-3213";
	BigInt c(s);
	//c.decrease();
	//c.print(std::cout);
	std::cout << std::endl;
	b.print(std::cout);
	b.increase();
	b.decrease();
	return 0;
}