#include <iostream>
#include "rDescriptor.h"
#include "wDescriptor.h"
#include "Table.h"
#include "md5.h"
#include <string>
#include "MyMap.h"

using namespace Prog4;
int main()
{
	MyMap<std::string, descriptor*> map;
	std::string name1 = "Iphone", firm1 = "Apple",country1 = "Russia";
	int count1 = 32, cost1 = 100;
	std::string name2 = "Mac", firm2 = "Apple", country2 = "USA";
	int count2 = 42, cost2 = 300;
	wDescriptor w(name2, "4", country2, count2, cost2, 10);
	rDescriptor r(name1, "2", country1, count1, cost1, 120);
	rDescriptor r1("dsad", "1", "ewqds", 21, 424, 122);
	wDescriptor w1("sda", "3", "dsafg", 34, 12, 532);
	rDescriptor r2("", "5", "", 42, 421, 123);
	std::string str = get_md5(r1.getName());
	Table t;
	return 0;
}