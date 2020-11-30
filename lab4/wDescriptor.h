#pragma once
#include "descriptor.h"

namespace Prog4 {
	class wDescriptor : public descriptor
	{
	private:
		int countWholesale;
	public:
		//constructors
		wDescriptor() : descriptor(), countWholesale(0) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1) : descriptor(name1, firm1, country1), countWholesale(0) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1, int cost1) :
			descriptor(name1, firm1, country1, cost1), countWholesale(1) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1) :
			descriptor(name1, firm1, country1, count1, cost1), countWholesale(0) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1, int CW) :
			descriptor(name1, firm1, country1, count1, cost1), countWholesale(CW) {}
		//getters
		int getCountWholesale() { return countWholesale; }
		//setters
		void setCountWholesale(int newCW) {
			if (newCW >= 0)
				countWholesale = newCW;
			else std::cout << "New wholesale quantity less than 0";
		}
		void getConvert() {
			std::cout << "from wDescriptor" << std::endl;
		}
	};
}