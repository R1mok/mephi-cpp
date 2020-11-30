#include <iostream>
#include "rDescriptor.h"
#include "wDescriptor.h"
#include "Table.h"

#include <string>

using namespace Prog4;
int main()
{
	std::string name1 = "Iphone", firm1 = "Apple",country1 = "Russia";
	int count1 = 32, cost1 = 10000;
	std::string name2 = "Mac", firm2 = "Apple", country2 = "USA";
	int count2 = 16, cost2 = 34123;
	rDescriptor r(name1, firm1, country1, count1, cost1, 123);
	wDescriptor w(name2, firm2, country2, count2, cost2, 153);
	Table array;
	array.add(r, 423);
	array.add(w, 764);
	return 0;
}