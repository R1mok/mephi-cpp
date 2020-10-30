#include <iostream>
#include <cmath>
#include "../lab3b/BigInt.h"


using namespace Prog3b;
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
	std::cout << "Write first number:";
	std::cin >> n1;
	std::cout << "Write second number:";
	std::cin >> n2;
	while (1) {
		for (int i = 0; i < countMessage; ++i)
			std::cout << message[i] << std::endl;
		std::cin >> c;
		if (c == 1) {
			n3 = n1 + n2;
			std::cout << "Result is: " << n3 << std::endl << "Success" << std::endl;
		}
		if (c == 2) {
			n3 = n1 - n2;
			std::cout << "Result is: " << n3 << "Success" << std::endl;
		}
		if (c == 3) {
			n1.increase();
			n2.increase();
			std::cout << "First number: " << n1 << "Second number: " << n2 << std::endl;
		}
		if (c == 4) {
			n1.decrease();
			n2.decrease();
			std::cout << "First number: " << n1 << "Second number: " << n2 << std::endl;
		}
		if (c == 5) {
			n1 = ~n1;
			n2 = ~n2;
			std::cout << "First number: " << n1 << "Second number: " << n2 << std::endl;
		}
		if (c == 0)
			break;
	}
	return 0;
}