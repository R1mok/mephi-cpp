#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cmath>
#include <string.h>
#include <iostream>

namespace Prog3b {
	class BigInt {
	public:
		// Constructors
		BigInt() :count(0) {
			for (int i = 0; i <= _MAX_COUNT; ++i)
				num[i] = '0';
		}
		BigInt(long& value);
		BigInt(const char*& string);

		//geters
		int getCount() const { return count; } // get count of digit in number
		int getMaxCount() const { return _MAX_COUNT; } // get max count of digit in number
		char getSign() const { return num[_MAX_COUNT]; } // get sign
		char getDigit(int i) const { return num[i]; } // get one digit for the index

		//setters
		void setDigit(int index, char digit) { num[index] = digit; } //set one digit of number
		void setCount(int c) { count = c; } //set count of digit in number

		//other methods
		friend std::ostream& operator<<(std::ostream& stream, const BigInt& number);
		friend std::istream& operator>>(std::istream& stream, BigInt& number);
		const BigInt operator~() const;
		void increase(); // * 10
		void decrease(); // dim 10
		const BigInt operator+(const BigInt& number) const;
		const BigInt operator-(const BigInt& number) const;
		const BigInt operator=(const BigInt& number);
	private:
		static const int _MAX_COUNT = 13; // max digit
		int count; // digit in number
		char num[_MAX_COUNT + 1]; // number
	};
}
#endif