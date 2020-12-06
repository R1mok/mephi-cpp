#pragma once
#include "descriptor.h"
#include "md5.h"
#include <vector>
#include <map>

namespace Prog4 {
	class Table
	{
	private:
		int n;
		static const int N = 10;
		std::map<std::string, descriptor*> ar; // map
	public:
		//constructors
		Table() : n(0) {}
		~Table() { ar.clear(); }
		//getters
		int getN() { return n; }
		void setN(int newN) {
			if (newN >= 0)
				n = newN;
			else std::cout << "New n less than 0";
		}
		// other methods
		int DFind(std::string);
		descriptor* find(std::string);
		int add(descriptor& val);
		void show();
		int del(std::string ciph);
	};
}
