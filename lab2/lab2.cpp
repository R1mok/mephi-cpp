// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include "Nephroid.h"
#include "NephroidMethods.h"

int main() {
	Prog2::Nephroid N(3, 2);
	int f11 = 1;
	char* s = NULL;
	while (f11) {
		std::cout << "Your Nephroid is: ";
		s = N.frm();
		std::cout << s << std::endl;
		delete[] s;
		std::cout << "Area: " << N.Area() << std::endl;
		std::cout << "Length: " << N.Length() << std::endl;
		std::cout << "Coordinate X: " << N.X_coord() << std::endl;
		std::cout << "Coordinate Y: " << N.Y_coord() << std::endl;
		double radius = 0;
		std::cout << "Change r: ";
		std::cin >> radius;
		N.setR(radius);
		double t;
		std::cout << "Change t: ";
		std::cin >> t;
		N.setT(t);
		std::cout << "Nephroid: " << N.frm() << std::endl;
		f11--;
	}
	return 0;
}