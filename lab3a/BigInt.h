#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cmath>
#include <string.h>
#include <iostream>

namespace Prog3a {
	class BigInt {
	public:
		// Constructors
		BigInt() :count(0) {
			for (int i = 0; i < _MAX_COUNT; ++i)
				num[i] = '0';
		}
		BigInt(long& value);
		BigInt(const char*& string);

		std::ostream& print(std::ostream& s) const; // number output

		//geters
		int getCount() const { return count; } // get count of digit in number
		int getMaxCount() const { return _MAX_COUNT; } // get max digit
		char getSign() const { return num[count]; } // get sign
		
		//setters
		//void setNewNum(int newCount, long newNum);
		void increase(); // * 10 
		void decrease(); // dim 10 
	private:
		static const int _MAX_COUNT = 47; // max digit  
		int count; // digit in number
		char num[_MAX_COUNT]; // number
	};
}
#endif