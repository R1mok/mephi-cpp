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
		void DFind(int ciph) {
			if (this->find(ciph) == nullptr) {
				std::cout << "Element not found" << std::endl;
			}
		}
		descriptor* find(int ciph) {
			int l = 0, r = 1'000'000;
			int curN = 0, m = 0;
			while (l <= r) {
				m = (l + r) / 2;
				TableElem curElem;
				curElem = this->ar[curN];
				if (curElem.cipher > m)
					l = ++m;
				else 
					r = --m;
				if (l == ciph || r == ciph)
					return curElem.ptr;
			}
			return nullptr;
		}
		int add(descriptor& val, int ciph) {
			int curN = 0;
			if (this->getN() >= N) {
				std::cout << "Array is full" << std::endl;
				return 1;
			}
			if (this->find(ciph) != nullptr) {
				std::cout << "Element with cipher already exist" << std::endl;
				return 1;
			}
			while (curN <= this->getN())
			{
				if (ciph < this->ar[0].cipher) {
					for (int i = this->getN() + 1; i > 0; --i)
						this->ar[i] = this->ar[i - 1];
					this->ar[0].ptr = &val;
					this->ar[0].cipher = ciph;
					this->setN(n + 1);
					break;
				}
				else if (ciph > this->ar[n].cipher) {
					int n1 = n + 1;
					if (this->ar[n].cipher == 0)
						--n1;
					this->ar[n1].ptr = &val;
					this->ar[n1].cipher = ciph;
					this->setN(n + 1);
					break;
				}
				else if (this->ar[curN].cipher < ciph && ciph < this->ar[curN + 1].cipher)
				{
					for (int i = this->getN() + 1; i > curN; --i)
						this->ar[i] = this->ar[i - 1];
					this->ar[curN].ptr = &val;
					this->ar[curN].cipher = ciph;
					this->setN(n + 1);
				}
			}
			return 0;
		}
	};
}
