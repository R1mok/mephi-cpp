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
	Table t;
	const char* message[] = {
		"0. Quit",
		"1.Insert or change product in table",
		"2.Sell product",
		"3.Show table" };
	const int countMessage = sizeof(message) / sizeof(message[0]);
	std::string name, firm, country;
	while (1) {
		int c;
		for (int i = 0; i < countMessage; ++i)
			std::cout << message[i] << std::endl;
		std::cin >> c;
		if (c == 0) {
			break;
		}
		if (c == 1) {
			char ans;
			std::cout << "Is it a wholesale or retail product? (w, r)" << std::endl;
			std::cin >> ans;
			if (ans == 'w') {
				int count, cost, wholesale;
				std::cout << "Enter product name: ";
				std::cin >> name;
				std::cout << "Enter firm: ";
				std::cin >> firm;
				std::cout << "Enter country: ";
				std::cin >> country;
				std::cout << "Enter product quantity: ";
				std::cin >> count;
				std::cout << "Enter product cost: ";
				std::cin >> cost;
				std::cout << "Enter the size of the wholesale: ";
				std::cin >> wholesale;
				std::cout << std::endl;
				wDescriptor* w = new wDescriptor;
				w->setCost(cost);
				w->setCount(count);
				w->setCountWholesale(wholesale);
				w->setFirm(firm);
				w->setCountry(country);
				w->setName(name); 
				descriptor* val = t.find(get_md5(w->getName()));
				if (val == nullptr)
					t.add(*w);
				else {
					w->setCount(val->getCount() + w->getCount());
					t.del(val->getName());
					t.add(*w);
				}
			}
			else if (ans == 'r') {
				int count, cost, allowance;
				std::cout << "Enter product name: ";
				std::cin >> name;
				std::cout << "Enter firm: ";
				std::cin >> firm;
				std::cout << "Enter country: ";
				std::cin >> country;
				std::cout << "Enter product quantity: ";
				std::cin >> count;
				std::cout << "Enter product cost: ";
				std::cin >> cost;
				std::cout << "Enter allowance: ";
				std::cin >> allowance;
				std::cout << std::endl;
				rDescriptor* r = new rDescriptor;
				r->setCost(cost);
				r->setCount(count);
				r->setAllowance(allowance);
				r->setFirm(firm);
				r->setCountry(country);
				r->setName(name);
				descriptor* val = t.find(r->getName());
				if (val == nullptr)
					t.add(*r);
				else {
					r->setCount(val->getCount() + r->getCount());
					t.del(val->getName());
					t.add(*r);
				}
			}
		}
		if (c == 2) {
			int count;
			std::cout << "Enter the name of the product you want to sell: ";
			std::cin >> name;
			std::cout << "Enter the count of products to sell: ";
			std::cin >> count;
			descriptor* val = t.find(get_md5(name));
			if (val == nullptr)
				std::cout << "Product with this name not found" << std::endl;
			else {
				double allcost = val->sale(count);
				t.del(name);
				t.add(*val);
				if (allcost > 0)
					std::cout << "Cost of goods sold: " << allcost << std::endl;
			}
		}
		if (c == 3) {
			t.show();
		}
	}
	return 0;
}