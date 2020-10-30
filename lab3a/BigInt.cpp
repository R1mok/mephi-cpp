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
			num[i] = (value % 10) + '0';
			value /= 10;
		}
		if (sign == false) // add sign in array
			num[_MAX_COUNT] = '9';
		else
		num[_MAX_COUNT] = '0';
		for (int i = count; i < _MAX_COUNT; ++i) {
			num[i] = '0';
		}
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
			count = strlen(string) - 1; // if number < 0, count of digits is less than one
			curNum = -curNum;
			sign = false;
		}
		else
			count = strlen(string);

		for (int i = 0; i < count; ++i) {
			num[i] = (curNum % 10) + '0';
			curNum /= 10;
		}
		if (sign == false) // add sign in array
			num[_MAX_COUNT] = '9';
		else
			num[_MAX_COUNT] = '0';
		for (int i = count; i < _MAX_COUNT; ++i) {
			num[i] = '0';
		}
	}
	std::ostream& BigInt::print(std::ostream& s) const {
		try {
			if (count == 0)
				throw std::range_error("Output error");
		}
		catch (std::range_error& error) {
			std::cerr << error.what() << std::endl;
		}
		if (count != 0 && num[_MAX_COUNT] == '9')
			s << "-";
		for (int i = count - 1; i >= 0; --i)
			s << num[i] - '0';
		s << std::endl;
		return s;
	}
	const BigInt BigInt::operator~() const {
		BigInt num(*this);
		if (num.getSign() == '9') {
			for (int i = 0; i < num.getMaxCount(); ++i)
				num.setDigit(i, (9 - (num.getDigit(i) - '0')) + '0');
			int i = 0, k = 0;
			while ((i < num.getCount() - 1) && num.getDigit(i) == '9') {
				num.setDigit(i, '0');
				k = ++i;
			}
			num.setDigit(k, ((num.getDigit(k) - '0') + 1) + '0');
			i = num.getCount() - 1;
			for ( ; num.getDigit(i) == '0' && i > 0; --i) // count last '0's (if they exist) and remove it
				;
			num.setCount(i + 1); // set count of digit without last '0's
		}
		return num;
	}
	void BigInt::increase() {
		try {
			if (count == _MAX_COUNT - 1)
				throw std::range_error("Number contains maximum of digits");
		}
		catch (std::range_error& error) {
			std::cerr << error.what() << std::endl;
		}
		count++;
		for (int i = count - 1; i >= 0; --i)
			num[i + 1] = num[i];
		num[0] = '0';
	}
	void BigInt::decrease() {
		count--;
		for (int i = 1; i <= count + 1; ++i)
			num[i - 1] = num[i];
		if (count == 0) {
			count = 1;
			num[0] = '0';
			num[_MAX_COUNT] = '0';
		}
	}
	const BigInt BigInt::add(BigInt& number) const {
		BigInt n1;
		n1 = (*this);
		n1 = ~n1;
		number = ~number;
		int q1, q2, rem = 0;
		for (int i = 0; i <= _MAX_COUNT; ++i) {
			q1 = (n1.getDigit(i)) - '0';
			q2 = (number.getDigit(i)) - '0';
			q1 = q1 + q2 + rem;
			n1.setDigit(i, (q1 % 10) + '0');
			rem = q1 / 10;
		}
		n1 = ~n1;
		number = ~number;
		if (n1.getDigit(n1.getCount()) == '1')
			n1.setCount(n1.getCount() + 1);
		int i = n1.getCount() - 1;
		while (n1.getDigit(i) == '0' && i > 0) {
			n1.setDigit(i, n1.getSign());
			--i;
		}
		n1.setCount(i + 1);
		return n1;
	}
	const BigInt BigInt::sub(BigInt& number) const {
		BigInt curNum = number;
		BigInt num = (*this);
		if (number.getSign() == '0')
			curNum.setDigit(curNum.getMaxCount(), '9');
		else
			curNum.setDigit(curNum.getMaxCount(), '0');
		num = (num).add(curNum);
		return num;
	}
	const BigInt BigInt::operator=(const BigInt& number) {
		for (int i = _MAX_COUNT; i >= 0; --i)
			(*this).num[i] = number.num[i];
		(*this).count = number.count;
		return *this;
	}
}