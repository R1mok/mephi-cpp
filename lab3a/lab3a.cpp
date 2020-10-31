#include <iostream>
#include <cmath>
#include "../lab3a/BigInt.h"


using namespace Prog3a;
int main()
{
	const char* message[] = {
		"0. Quit",
		"1.Add this numbers",
		"2.Sub this numbers",
		"3.Increase number",
		"4.Decrease number",
		"5.Get additional code" };
	const int countMessage = sizeof(message) / sizeof(message[0]);
	int c = 0;
	BigInt n1, n2, n3;
	const char* s = "-324";
	long l = -424231;
	n1 = s;
	n2 = l;
	while (1) {
		for (int i = 0; i < countMessage; ++i)
			std::cout << message[i] << std::endl;
		std::cin >> c;
		if (c == 1) {
			n3 = n1.add(n2);
			std::cout << "Result is: ";
			n3.print(std::cout);
			std::cout << "Success" << std::endl;
		}
		if (c == 2) {
			n3 = n1.sub(n2);
			std::cout << "Result is: ";
			n3.print(std::cout);
			std::cout << "Success" << std::endl;
		}
		if (c == 3) {
			n1.increase();
			n2.increase();
			std::cout << "First number: ";
			n1.print(std::cout);
			std::cout << "Second number: ";
			n2.print(std::cout);
		}
		if (c == 4) {
			n1.decrease();
			n2.decrease();
			std::cout << "First number: ";
			n1.print(std::cout);
			std::cout << "Second number: ";
			n2.print(std::cout);
		}
		if (c == 5) {
			n1 = ~n1;
			n2 = ~n2;
			std::cout << "First number: ";
			n1.print(std::cout);
			std::cout << "Second number: ";
			n2.print(std::cout);
		}
		if (c == 0)
			break;
	}
	return 0;
}