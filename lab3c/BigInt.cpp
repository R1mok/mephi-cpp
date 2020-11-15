#include "BigInt.h"

namespace Prog3c {
	BigInt::BigInt(int k, int) {
		count = k;
		if (k == 0)
			count++;
		num = new char[count + 1];
		for (int i = 0; i <= count; ++i)
			num[i] = '0';
	}
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
		num = new char[k + 1];
		count = k;
		for (int i = 0; i < k; ++i) {
			num[i] = (value % 10) + '0';
			value /= 10;
		}
		if (sign == false) // add sign in array
			num[count] = '9';
		else
			num[count] = '0';
	}
	BigInt::BigInt(const char*& string) {
		int s = strlen(string);
		long curNum = atol(string);
		bool sign = true;
		if (curNum < 0) {
			count = s - 1; // if number < 0, count of digits is less than one
			curNum = -curNum;
			sign = false;
		}
		else
			count = s;
		num = new char[count + 1];
		for (int i = 0; i < count; ++i) {
			num[i] = (curNum % 10) + '0';
			curNum /= 10;
		}
		if (sign == false) // add sign in array
			num[count] = '9';
		else
			num[count] = '0';
	}
	BigInt::BigInt(const BigInt& number, int m) {
		num = new char[number.count + m + 1];
		int i = 0;
		for (; i < number.count; ++i)
			num[i] = number.num[i];
		for (; i <= number.count + m; ++i)
			num[i] = '0';
		count = number.count + m;
		num[count] = number.getSign();
	}
	BigInt::~BigInt() {
		if (num) {
			delete[] num;
		}
	}
	std::ostream& operator<<(std::ostream& stream, const BigInt& number) {
		if (number.getSign() == '9') {
			stream << "-";
		}
		for (int i = number.getCount() - 1; i >= 0; --i)
			stream << number.getDigit(i) - '0'; // output int
		stream << std::endl;
		return stream;
	}
	std::istream& operator>>(std::istream& istream, BigInt& number) {
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
		int k = 1, c = strlen(out);
		if (atoi(out) < 0)
			k = 0;
		BigInt curNum(number, c + k - 1);
		for (int i = 0; i < c; ++i) {
			curNum.setDigit(c - i - 1, out[i]);
		}
		number = curNum;
		number.setCount(number.getCount() - 1);
		if (number.getDigit(number.getCount()) == '-')
			number.setDigit(number.getCount(), '9');
		if (out != nullptr)
			free(out);
		return istream;
	}
	const BigInt BigInt::operator~() const {
		BigInt num;
		num = *this;
		BigInt res(count, 1);
		if (num.getSign() == '9') {
			for (int i = 0; i < num.getCount(); ++i)
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

	BigInt BigInt::increase() {
		int curCount = count;
		curCount++;
		BigInt res(curCount, 1);
		if (num[0] == '0' && (curCount == 1 || curCount == 2)) {
			res.num[1] = '1';
		}
		else {
			for (int i = 1; i <= curCount; ++i) {
				res.num[i] = num[i - 1];
			}
		}
		res.num[0] = '0';
		return res;
	}

	BigInt BigInt::decrease() {
		int curCount = count;
		curCount--;
		BigInt res(curCount, 1);
		if (curCount == 0) {
			curCount = 1;
			num[0] = '0';
			num[curCount] = '0';
			return res;
		}
		for (int i = 1; i <= curCount + 1; ++i)
			res.num[i - 1] = num[i];
		return res;
	}

	const BigInt BigInt::operator+(const BigInt& number) const {
		BigInt res;
		res = *this;
		res = ~res;
		BigInt curNum;
		curNum = ~number;
		int q1, q2, rem = 0;
		if (res.count < curNum.count) {
			int d = curNum.count - res.count;
			BigInt res1(res, d);
			res.setCount(curNum.count);
			res = res1;
		}
		else if (res.count > curNum.count) {
			int d = res.count - curNum.count;
			BigInt curNum1(curNum, d);
			curNum = curNum1;
			curNum.setDigit(curNum.getCount() - d, curNum.getDigit(curNum.getCount()));
			if (curNum.getSign() == '9') {
				for (int i = curNum.getCount() - d; i <= curNum.getCount(); ++i)
					curNum.setDigit(i, '9');
			} else 
				curNum.setDigit(curNum.getCount(), '0');
			curNum.setCount(curNum.getCount() - d);
		}
		else {
			BigInt res1(res, 1);
			res = res1;
			res.setDigit(res.getCount() - 1, res.getDigit(res.getCount()));
			res.setDigit(res.getCount(), '0');
			res.setCount(res.getCount() - 1);
		}
		int l = res.count;
		bool equal = false;
		if (curNum.getSign() == '0' && res.getSign() == '0')
			equal = true;
		for (int i = 0; i <= l; ++i) {
			q1 = res.getDigit(i) - '0';
			q2 = (curNum.getDigit(i)) - '0';
			q1 = q1 + q2 + rem;
			res.setDigit(i, (q1 % 10) + '0');
			rem = q1 / 10;
			if (i + 1 == res.count && rem != 0 && equal) {
				res.setCount(res.getCount() + 1);
			}
		}
		res = ~res;
		if (res.getCount() <= curNum.getCount()) // set count of 2 numbers
			res.setCount(curNum.getCount());
		int i = res.getCount() - 1;
		while (res.getDigit(i) == '0' && i > 0) { // if we have insignificant zeros, we remove they
			res.setDigit(i, res.getSign());
			--i;
		}
		if (res.getSign() != '0' && res.getSign() != '9') {
			res.setDigit(res.getCount(), '0');
		}
		res.setCount(i + 1);
		return res;
	}

	const BigInt BigInt::operator-(const BigInt& number) const {
		BigInt curNum;
		BigInt res;
		res = *this;
		curNum = number;
		if (number.getSign() == '0')
			curNum.setDigit(number.getCount(), '9');
		else
			curNum.setDigit(number.getCount(), '0');
		res = res + curNum;
		return res;
	}

	BigInt& BigInt::operator=(const BigInt& number) {
		if (this->num != number.num) {
			if (num != nullptr)
				delete[] num;
			if (number.count != 0) {
				count = number.count;
				num = new char[number.count + 1];
				for (int i = 0; i <= count; ++i)
					num[i] = number.num[i];
			}
		}
		return *this;
	}
	BigInt& BigInt::operator=(BigInt&& number) noexcept {
		delete[] num;
		num = number.num;
		count = number.count;
		number.num = nullptr;
		return *this;
	}
}