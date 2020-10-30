#include "BigInt.h"

namespace Prog3b {
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
	std::ostream& operator<<(std::ostream& stream, const BigInt& number) {
		if (number.getSign() == '9') {
			stream << "-";
		}
		for (int i = number.getCount() - 1; i >= 0; --i)
			stream << number.getDigit(i) - '0';
		stream << std::endl;
		return stream;
	}
	std::istream& operator>>(std::istream& istream, BigInt& number) {
		for (int i = 0; i < number.getMaxCount(); ++i)
			number.setDigit(i, '0');
		char* out = (char*)malloc(1), buf[35];
		int n = 0, l = 0;
		out[0] = '\0';
		do {
			n = scanf_s("%34[^\n]", buf, 35);
			if (n < 0)
				delete out;
			if (n > 0) {
				l += strlen(buf);
				out = (char*)realloc(out, l + 1);
				strcat_s(out, l + 1, buf);
			}
			if (n == 0)
				scanf_s("%*c");
		} while (n > 0);
		try {
			int i = 0;
			int c = strlen(out);
			if (c >= number.getMaxCount())
				throw std::range_error("Number contains maximum of digits");
			for (; i < c; ++i) {
				number.setDigit(c - i - 1, out[i]);
			}
			if (number.getDigit(c - 1) == '-') {
				number.setDigit(c - 1, '0');
				number.setDigit(number.getMaxCount(), '9');
				number.setCount(c - 1);
			}
			else
				number.setCount(c);
		}
		catch (std::range_error& error) {
			std::cerr << error.what() << std::endl;
		}
		free(out);
		return istream;
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
			for (; num.getDigit(i) == '0' && i > 0; --i) // count last '0's (if they exist) and remove it
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
	const BigInt BigInt::operator+(const BigInt& number) const {
		BigInt res(*this);
		res = ~res;
		BigInt curNum;
		curNum = ~number;
		int q1, q2, rem = 0;
		for (int i = 0; i <= _MAX_COUNT; ++i) {
			q1 = (res.getDigit(i)) - '0';
			q2 = (curNum.getDigit(i)) - '0';
			q1 = q1 + q2 + rem;
			res.setDigit(i, (q1 % 10) + '0');
			rem = q1 / 10;
		}
		res = ~res;
		if (res.getDigit(res.getCount()) == '1')
			res.setCount(res.getCount() + 1);
		int i = res.getCount() - 1;
		while (res.getDigit(i) == '0' && i > 0) {
			res.setDigit(i, res.getSign());
			--i;
		}
		res.setCount(i + 1);
		return res;
	}
	const BigInt BigInt::operator-(const BigInt& number) const {
		BigInt curNum = number;
		if (number.getSign() == '0')
			curNum.setDigit(curNum.getMaxCount(), '9');
		else
			curNum.setDigit(curNum.getMaxCount(), '0');
		return (*this + curNum);
	}
	const BigInt BigInt::operator=(const BigInt& number) {
		for (int i = _MAX_COUNT; i >= 0; --i)
			(*this).num[i] = number.num[i];
		(*this).count = number.count;
		return *this;
	}
}