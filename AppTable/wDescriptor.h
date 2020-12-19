#pragma once
#include "descriptor.h"

namespace Prog4 {
	class wDescriptor : public descriptor
	{
	protected:
		int countWholesale;
		std::ostream& show(std::ostream&)const;
		std::istream& get(std::istream&);
	public:
		//constructors
		wDescriptor() : descriptor(), countWholesale(0) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1) : descriptor(name1, firm1, country1), countWholesale(0) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1) :
			descriptor(name1, firm1, country1, count1, cost1), countWholesale(0) {}
		wDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1, int CW) :
			descriptor(name1, firm1, country1, count1, cost1), countWholesale(CW) {}
		wDescriptor(const wDescriptor& a) : descriptor(a), countWholesale(a.countWholesale) {} //copy
		//getters
		int getCountWholesale() { return countWholesale; }
		char getType()const { return 'w'; }
		//setters
		void setCountWholesale(int newCW);
		double sale(int wholesale);
		descriptor* getConvert(int newAllowance);
	};
}