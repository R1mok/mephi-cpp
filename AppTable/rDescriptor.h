#pragma once
#include "descriptor.h"

namespace Prog4 {
	class rDescriptor : public descriptor
	{
	protected:
		int allowance;
		std::ostream& show(std::ostream&)const;
		std::istream& get(std::istream&);
	public:
		//constructors
		rDescriptor() : descriptor(), allowance(0) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1) : descriptor(name1, firm1, country1), allowance(100) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1) :
			descriptor(name1, firm1, country1, count1, cost1), allowance(100) {}
		rDescriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1, int allowance1) :
			descriptor(name1, firm1, country1, count1, cost1), allowance(allowance1) {}
		rDescriptor(const rDescriptor& a) : descriptor(a), allowance(a.allowance) {} //copy
		//getters
		int getAllowance() { return allowance; }
		char getType()const { return 'r'; }
		//setters
		void setAllowance(int newAllowance);
		double sale(int saleCount);
		descriptor* getConvert(int newWholesale);
	};
}