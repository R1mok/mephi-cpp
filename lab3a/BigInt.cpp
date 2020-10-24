#include "BigInt.h"

namespace Prog3a {
	BigInt::BigInt(long& value) {
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
		if (sign == false) // добавляем знак числа
			num[count] = '-';
		else 
			num[count] = '+';
	}
	BigInt::BigInt(const char*& string) {
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
			count = strlen(string) - 1; // если число < 0, то цифр в числе на 1 меньше,
			curNum = -curNum; // чем количество символов
			sign = false;
		} else 
			count = strlen(string);

		for (int i = 0; i < count; ++i) {
			num[i] = curNum % 10;
			curNum /= 10;
		}
		if (sign == false) // добавляем знак
			num[count] = '-';
		else 
			num[count] = '+';
	}
	std::ostream& BigInt::print(std::ostream& s) const {
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
	void BigInt::increase() {
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
	void BigInt::decrease() {
		count--;
		for (int i = 1; i <= count + 1; ++i)
			num[i - 1] = num[i];
	}
}