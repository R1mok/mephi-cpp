#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cmath>
#include <string.h>
#include <iostream>

namespace Prog3a {
	class BigInt {
	public:
		// Конструкторы
		BigInt() :count(0) {
			for (int i = 0; i < _MAX_COUNT; ++i)
				num[i] = '0';
		}
		BigInt(long& value);
		BigInt(const char*& string);

		std::ostream& print(std::ostream& s) const; // вывод числа

		//geters
		int getCount() const { return count; } // получить количество цифр в числе
		int getMaxCount() const { return _MAX_COUNT; } // получить максимальное число цифр в числе
		char getSign() const { return num[count]; } // получить знак числа
		
		//setters
		//void setNewNum(int newCount, long newNum);
		void increase(); // * 10 
		void decrease(); // dim 10 
	private:
		static const int _MAX_COUNT = 47; // максимальный размер цифр в числе	 
		int count; // количество цифр в числе
		char num[_MAX_COUNT]; // число
	};
}
#endif