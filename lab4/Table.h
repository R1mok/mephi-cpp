#pragma once
#include "descriptor.h"

namespace Prog4 {
	typedef struct TableElem {
		int cipher;
		descriptor* ptr;
	}TableElem;
	class Table
	{
	private:
		int n;
		static const int N = 10;
		TableElem ar[N];
	public:
		//constructors
		Table() : n(0) {
			for (int i = 0; i < N; ++i)
				ar[i].cipher = 0, ar[i].ptr = nullptr;
		}
		//getters
		int getN() { return n; }
		void setN(int newN) {
			if (newN >= 0)
				n = newN;
			else std::cout << "New n less than 0";
		}
		// other methods
		void DFind(int ciph);
		descriptor* find(int ciph);
		int add(descriptor& val, int ciph);
		void show();
		int del(int ciph);
	};
}
