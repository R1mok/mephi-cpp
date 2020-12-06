#include <iostream>
#include "rDescriptor.h"
#include "wDescriptor.h"
#include "Table.h"
#include "md5.h"
#include <string>

using namespace Prog4;
int main()
{
	std::string name1 = "Iphone", firm1 = "Apple",country1 = "Russia";
	int count1 = 32, cost1 = 100;
	std::string name2 = "Mac", firm2 = "Apple", country2 = "USA";
	int count2 = 42, cost2 = 300;
	wDescriptor w(name2, firm2, country2, count2, cost2, 10);
	rDescriptor r(name1, firm1, country1, count1, cost1, 120);
	rDescriptor m;
	Table t;
	int count = 21, cost = 42, allowance = 120;
	wDescriptor w1("namer", "countryr", "firmr", count, cost, allowance);
	int all = w1.sale(5);
	std::cout << all << std::endl;
	std::cout << w1;
 	return 0;
}