#include "rDescriptor.h"
#include "wDescriptor.h"
#include <iostream>

namespace Prog4 {
	void rDescriptor::setAllowance(int newAllowance) {
		if (newAllowance >= 100)
			allowance = newAllowance;
		else
			std::cout << "New allowance less than 100%" << std::endl;
	}
	std::ostream& rDescriptor::show(std::ostream& os) const {
		descriptor::show(os);
		return os << " allowance: " << allowance;
	}
	std::istream& rDescriptor::get(std::istream& is) {
		descriptor::get(is);
		int allowance1;
		std::cout << "allowance: ";
		is >> allowance1;
		allowance = allowance1;
		return is;
	}
	double rDescriptor::sale(int saleCount) {
		double AllCost;
		if (saleCount > this->getCount()) {
			return -1;
		}
		AllCost = (double)(this->getAllowance() / 100.0) * (this->getCost()) * saleCount;
		this->setCount(this->getCount() - saleCount);
		return AllCost;
	}
	descriptor* rDescriptor::getConvert(int newCountWholesale) {
		wDescriptor* newVal = new wDescriptor;
		newVal->setName(this->getName());
		newVal->setFirm(this->getFirm());
		newVal->setCountry(this->getCountry());
		newVal->setCost(this->getCost());
		newVal->setCount(this->getCount());
		newVal->setCountWholesale(newCountWholesale);
		return newVal;
	}
}