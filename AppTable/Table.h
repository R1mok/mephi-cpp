#pragma once
#include "descriptor.h"
#include "md5.h"
#include <vector>
#include <map>
#include "MyMap.h"

namespace Prog4 {
	class Table
	{
	private:
		int n;
		static const int N = 10;
		MyMap<std::string, descriptor*> ar; // map // + list
	public:
		//constructors
		Table() : n(0) {}
		~Table() { } // desctructor include in MyMap
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
		int del(std::string name);
		std::string getEl();
		int changeEl(descriptor* a, int newVal);
	};
}