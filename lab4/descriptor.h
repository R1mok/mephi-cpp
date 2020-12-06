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
		virtual std::ostream& show(std::ostream&) const = 0;
		virtual std::istream& get(std::istream&) = 0;
	public:
		//constructors
		descriptor() : name(""), firm(""), country(""), count(0), cost(0) { }
		descriptor(std::string name1, std::string firm1, std::string country1) : name(name1), firm(firm1), country(country1), cost(0), count(0) {}
		//descriptor(std::string name1, std::string firm1, std::string country1, int cost1) :
			//name(name1), firm(firm1), country(country1), cost(cost1), count(1) {}
		descriptor(std::string name1, std::string firm1, std::string country1, int count1, int cost1) :
			name(name1), firm(firm1), country(country1), cost(cost1), count(count1) {}
		virtual ~descriptor() {}
		//getters
		std::string getName() { return name; }
		std::string getFirm() { return firm; }
		std::string getCountry() { return country; }
		int getCount() { return count; }
		int getCost() { return cost; }
		virtual char getType() const = 0;
		//setters
		void setName(std::string newName) { name = newName; }
		void setFirm(std::string newFirm) { firm = newFirm; }
		void setCountry(std::string newCountry) { country = newCountry; }
		void setCount(int newCount);
		void setCost(int newCost);
		// other methods
		virtual double sale(int val) = 0;
		friend std::ostream& operator<<(std::ostream&, const descriptor&);
		friend std::istream& operator>>(std::istream&, descriptor&);
	};

}