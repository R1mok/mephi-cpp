#include <iostream>
#include <cmath>
#include "../lab3a/BigInt.h"


using namespace Prog3a;
int main()
{
	BigInt a;
	//testing construct
	std::cout << "a:";
	a.print(std::cout);
	long bValue = 302;
	std::cout << "b:";
	BigInt b(bValue);
	b.print(std::cout);
	std::cout << "c:";
	const char* cValue = "-321";
	BigInt c(cValue);
	c.print(std::cout);
	//testing getters
	std::cout << "Last digit of a: " << a.getDigit(0) << " b:" << b.getDigit(0);
	std::cout << " c:" << c.getDigit(0) << std::endl;
	std::cout << "Count of digit: a:" << a.getCount() << " b:" << b.getCount();
	std::cout << " c:" << c.getCount() << std::endl;
	std::cout << "Max count " << a.getMaxCount() << std::endl;
	std::cout << "Sign: a:" << a.getSign() << " b:" << b.getSign();
	std::cout << " c:" << c.getSign() << std::endl;
	//testing setters
	long s1num;
	std::cout << "Write number: ";
	std::cin >> s1num;
	BigInt s1(s1num);
	int k;
	std::cout << "Set new first digit: ";
	char s2;
	std::cin >> s2;
	s1.setDigit(s1.getCount() - 1, s2);
	std::cout << "New number: ";
	s1.print(std::cout);
	std::cout << "Set count of digit: ";
	std::cin >> k;
	s1.setCount(k);
	std::cout << "New count is: " << s1.getCount() << std::endl;
	//testing methods
	BigInt d = b;
	b = b.add(c);
	c = c.add(d);
	std::cout << "b = b + c: ";
	b.print(std::cout);
	std::cout << "c = c + b: ";
	c.print(std::cout);
	c = c.sub(b);
	std::cout << "c = c - b: ";
	c.print(std::cout);
	std::cout << "b: ";
	b.print(std::cout);
	b.increase();
	std::cout << "Increase b: ";
	b.print(std::cout);
	b.decrease();
	std::cout << "Decrease b: ";
	b.print(std::cout);
	b.decrease();
	std::cout << "Decrease b: ";
	b.print(std::cout);
	b.increase();
	std::cout << "Increase b: ";
	b.print(std::cout);
	return 0;
}