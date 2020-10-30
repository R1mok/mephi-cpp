#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cmath>
#include <string.h>
#include <iostream>

namespace Prog3a {
	class BigInt {
	public:
		// Constructors
		BigInt() :count(1) {
			for (int i = 0; i <= _MAX_COUNT; ++i)
				num[i] = '0';
		}
		BigInt(long& value);
		BigInt(const char*& string);

		std::ostream& print(std::ostream& s) const; // output of number
		const BigInt operator~() const;

		//geters
		int getCount() const { return count; } // get count of digit in number
		int getMaxCount() const { return _MAX_COUNT; } // get max count of digit in number
		char getSign() const { return num[_MAX_COUNT]; } // get sign
		char getDigit(int i) const { return num[i]; } // get one digit for the index

		//setters
		void setDigit(int index, char digit) { num[index] = digit; }
		void setCount(int c) { count = c; }

		//other methods
		void increase(); // * 10
		void decrease(); // dim 10
		const BigInt add(BigInt& number) const;
		const BigInt sub(BigInt& number) const;
		const BigInt operator=(const BigInt& number);
	private:
		static const int _MAX_COUNT = 13; // max digit
		int count; // digit in number
		char num[_MAX_COUNT + 1]; // number
	};
}
#endif