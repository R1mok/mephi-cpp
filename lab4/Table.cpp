#include "Table.h"
#include "descriptor.h"
namespace Prog4 {

	int Table::add(descriptor& val) {
		std::string ciph = get_md5(val.getName());
		int curN = 0;
		if (this->getN() >= N) {
			std::cout << "Array is full" << std::endl;
			return -1;
		}
		if (this->find(ciph) != nullptr) {
			std::cout << "Element with cipher already exist" << std::endl;
			return -1;
		}
			this->ar[ciph] = &val;
		this->setN(this->getN() + 1);
		return 0;
	}
	descriptor* Table::find(std::string ciph) {
		for (auto i : this->ar) {
			if (i.first == ciph)
				return i.second;
		}
		return nullptr;
	}
	int Table::DFind(std::string ciph) {
		if (this->find(ciph) == nullptr) {
			std::cout << "Element not found" << std::endl;
			return -1;
		}
		return 0;
	}
	int Table::del(std::string name) {
		std::string	ciph = get_md5(name);
		if (this->DFind(ciph) == 0) {
			this->ar.erase(ciph);
			this->setN(this->getN() - 1);
			return 0;
		} else return -1;
	}
	void Table::show() {
		for (auto i : this->ar) {
			std::cout << "Cipher: " << i.first << " " << *i.second << std::endl;
		}
	}
	int Table::changeEl(descriptor* val, int newVal) {
		descriptor* a;
		a = val->getConvert(newVal);
		this->del(get_md5(val->getName()));
		this->add(*a);
		return 0;
	}
}