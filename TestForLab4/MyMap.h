#pragma once
#include <exception>

template <class CIPH, class VAL>
struct Pair {
	CIPH first;
	VAL second;
	Pair():first(CIPH()), second() {}
	Pair(const CIPH &name, VAL val): first(name), second(val) {}
};
template<class CIPH, class VAL>
class MyMap
{
private:
	static const int QUOTA = 10;
	int count, cur;
	Pair<CIPH, VAL>* ar;
	int getPos(const CIPH&) const;
public:
	MyMap(): count(QUOTA), cur(0), ar(new Pair<CIPH, VAL>[QUOTA]) {}
	MyMap(const MyMap<CIPH, VAL>&);
	~MyMap() { delete ar };
	MyMap<CIPH, VAL>& operator = (const MyMap<CIPH, VAL>&);
	VAL& operator[](const CIPH&); // l-value
	const VAL& operator[](const CIPH&) const; // r-value
};

template <class CIPH, class VAL>
MyMap<CIPH, VAL>::MyMap(const MyMap<CIPH, VAL>& a) : count(a.count), cur(a.cur), ar(new Pair[a.count]) {
	for (int i = 0; i < count; ++i)
		ar[i] = a.ar[i];
}
template<class CIPH, class VAL>
MyMap<CIPH, VAL>& MyMap<CIPH, VAL>::operator=(const MyMap<CIPH, VAL>& a) {
	if (this != &a) {
		delete[] ar;
		ar = new Pair<CIPH, VAL>[count = a.count];
		cur = a.cur;
		for (int i = 0; i < count; ++i)
			ar[i] = a.ar[i];
	}
}
template<class CIPH,class VAL>
int MyMap<CIPH, VAL>::getPos(const CIPH& s) const {
	for (int i = 0; i < cur; ++i)
		if (ar[i].first == s)
			return i;
	return -1;
}
template <class CIPH, class VAL> // l-value
VAL& MyMap<CIPH, VAL>::operator[](const CIPH& s) {
	int i = getPos(s);
	if (i < 0) {
		i = cur;
		if (cur >= count) {
			Pair<CIPH, VAL>* old = ar;
			ar = new Pair<CIPH, VAL>[count += QUOTA];
			for (i = 0; i < cur; ++i)
				ar[i] = old[i];
			delete[] old;
		}
		ar[cur].first = s;
		++cur;
	}
	return ar[i].second;
}
template <class CIPH, class VAL> // r-value
const VAL& MyMap<CIPH, VAL>::operator[](const CIPH& s) const {
	int i = getPos(s);
	if (i < 0)
		throw std::exception("Illegal index");
	return ar[i].second;
}