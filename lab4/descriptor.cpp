#include "descriptor.h"
#include <iostream>

namespace Prog4 { // w â r constructor
	void descriptor::setCount(int newCount) {
		if (newCount >= 0)
			count = newCount;
		else std::cout << "New count less than 0" << std::endl;
	}
	void descriptor::setCost(int newCost) {
		if (newCost >= 0)
			cost = newCost;
		else std::cout << "New cost less than 0" << std::endl;
	}
	std::ostream& descriptor::show(std::ostream& os) const {
		os << "Name: " << name << " firm: " << firm << " country: " << country << " count: " << count << " cost: " << cost;
		return os;
	}
	std::istream& descriptor::get(std::istream& is) {
		std::string name1, firm1, country1;
		int count1, cost1;
		std::cout << "Name: ";
		is >> name1;
		name = name1;
		std::cout << "firm: ";
		is >> firm1;
		firm = firm1;
		std::cout << "country: ";
		is >> country1;
		country = country1;
		std::cout << "count: ";
		is >> count1;
		count = count1;
		std::cout << "cost: ";
		is >> cost1;
		cost = cost1;
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const descriptor& p) {
		return p.show(os);
	}
	std::istream& operator>>(std::istream& is, descriptor& p) {
		return p.get(is);
	}
}