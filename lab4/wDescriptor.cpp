#include "wDescriptor.h"
#include "rDescriptor.h"
#include <iostream>

namespace Prog4 {
	void wDescriptor::setCountWholesale(int newCW) {
		if (newCW >= 0)
			countWholesale = newCW;
		else std::cout << "New wholesale quantity less than 0";
	}
	std::ostream& wDescriptor::show(std::ostream& os) const {
		descriptor::show(os);
		return os << " countWholesale: " << countWholesale;
	}
	std::istream& wDescriptor::get(std::istream& is) {
		descriptor::get(is);
		int countWholesale1;
		std::cout << "Count of wholesale: ";
		is >> countWholesale1;
		countWholesale = countWholesale1;
		return is;
	}
	double wDescriptor::sale(int wholesale) {
		double AllCost;
		if (wholesale > this->getCount()) {
			std::cout << "Count of wholesale more than available count" << std::endl;
			return -1;
		}
		AllCost = double(wholesale) * double(this->getCost()) * double(this->getCountWholesale());
		this->setCount(this->getCount() - wholesale);
		return AllCost;
	}
}