#pragma once
#include <string>
#include <iostream>

namespace Prog4 {
	
	class descriptor
	{
	protected:
		std::string name;
		std::string firm, country;
		int count, cost;
		bool type; // 1 - wDescriptor, 0 - rDescriptor
	public:
		//constructors
		descriptor() : name(""), firm(""), country(""), count(0), cost(0), type(0) { }
		descriptor(std::string name1, std::string firm1, std::string country1) : name(name1), firm(firm1), country(country1), cost(0), count(1), type(0) {}
		descriptor(std::string name1, std::string firm1, std::string country1, int cost1) :
			name(name1), firm(firm1), country(country1), cost(cost1), count(1), type(0) {}
		descriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1) :
			name(name1), firm(firm1), country(country1), cost(cost1), count(count1), type(0) {}
		//getters
		std::string getName() { return name; }
		std::string getFirm() { return firm; }
		std::string getCountry() { return country; }
		int getCount() { return count; }
		int getCost() { return cost; }
		bool getType() { return type; }
		//setters
		void setCount(int newCount) {
			if (newCount >= 0)
				count = newCount;
			else std::cout << "New count less than 0" << std::endl;
		}
		void setCost(int newCost) {
			if (newCost >= 0)
				cost = newCost;
			else std::cout << "New cost less than 0" << std::endl;
		}
		void setType(bool newType) { type = newType; }
		// virtual function
		virtual void getConvert() = 0;
	};

}