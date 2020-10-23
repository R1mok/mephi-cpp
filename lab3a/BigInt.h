#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cmath>
#include <string.h>
#include <iostream>

namespace Prog3a {
	class BigInt {
	public :
		BigInt() :count(0) {
			for (int i = 0; i < _MAX_COUNT; ++i)
				num[i] = '0';
		}
		BigInt(long &value) {
			bool sign = true;
			if (value < 0) {
				sign = false;
				value = -value;
			}
			int k = 0;
			long cur = value;
			while (cur > 0) {
				++k;
				cur /= 10;
			}
			try {
				if (_MAX_COUNT < k)
					throw std::range_error("Number value is too large");
			}
			catch (std::range_error& error) {
				std::cerr << error.what() << std::endl;
			}
			count = k;
			for (int i = 0; i < k; ++i) {
				num[i] = value % 10;
				value /= 10;
			}
			if (sign == false)
				num[count] = '-';
			else num[count] = '+';
		}

		BigInt(const char*& string) {
			int s = strlen(string);
			try {
				if (_MAX_COUNT <= s)
					throw std::range_error("String too large");
			}
			catch (std::range_error& error) {
				std::cerr << error.what() << std::endl;
			}
			long curNum = atol(string);
			bool sign = true;
			if (curNum < 0) {
				count = strlen(string) - 1;
				curNum = -curNum;
				sign = false;
			}

			else count = strlen(string);

			for (int i = 0; i < count; ++i) {
				num[i] = curNum % 10;
				curNum /= 10;
			}
			if (sign == false)
				num[count] = '-';
			else num[count] = '+';
		};

		std::ostream& print(std::ostream& s) const {
			try {
				if (count == 0 || num[0] == '-')
					throw std::range_error("Output error");
			}
			catch (std::range_error& error) {
				std::cerr << error.what() << std::endl;
			}
			if (count != 0 && num[count] == '-')
				s << "-";
			for (int i = count - 1; i >= 0; --i)
				s << int(num[i]);
			s << std::endl;
			return s;
		}

	//geters
		int getCount() const { return count; }
		int getMaxCount() const { return _MAX_COUNT; }
		char getSign() const { return num[count]; }
	//setters
		//void setNewNum(int newCount, long newNum);
		void increase() {
			try {
				if (count + 1 == _MAX_COUNT)
					throw std::range_error("Number contains maximum of digits");
			}
			catch (std::range_error& error) {
				std::cerr << error.what() << std::endl;
			}
			count++;
			for (int i = count - 1; i >= 0; --i)
				num[i + 1] = num[i];
			num[0] = 0;
		}
		void decrease() {
			count--;
			for (int i = 1; i <= count + 1; ++i)
				num[i - 1] = num[i];
		}
	private:
		static const int _MAX_COUNT = 47; // максимальный размер цифр в числе	 
		int count; // количество цифр в числе
		char num[_MAX_COUNT]; // число
	};
}
#endif