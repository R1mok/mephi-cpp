#pragma once
#include "descriptor.h"

namespace Prog4 {
	class rDescriptor : public descriptor
	{
	private:
		int allowance;
	public:
		//constructors
		rDescriptor() : descriptor(), allowance(0) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1) : descriptor(name1, firm1, country1), allowance(100) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1, int cost1) :
			descriptor(name1, firm1, country1, cost1), allowance(100) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1) :
			descriptor(name1, firm1, country1, count1, cost1), allowance(100) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1, int allowance1) :
			descriptor(name1, firm1, country1, count1, cost1), allowance(allowance1) {}
		//getters
		int getAllowance() { return allowance; }
		//setters
		void setAllowance(int newAllowance) {
			if (newAllowance >= 100)
				allowance = newAllowance;
			else std::cout << "New allowance less than 100%";
		}
		void getConvert() {
			std::cout << "from rDescriptor" << std::endl;
		}
	};
}

