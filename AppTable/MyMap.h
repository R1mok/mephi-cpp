#pragma once
#include <exception>

template <class CIPH, class VAL>
struct Pair {
	CIPH first;
	VAL second;
	Pair() :first(CIPH()), second(VAL()) {}
	Pair(const CIPH& name, VAL val) : first(name), second(val) {}
};

template<class CIPH, class VAL>
class Iter;

template<class CIPH, class VAL>
class MyMap
{
	friend	class Iter<CIPH, VAL>;
private:
	static const int QUOTA = 10;
	int count, cur;
	Pair<CIPH, VAL>* ar;
	int getPos(const CIPH&) const;
public:
	MyMap() : count(QUOTA), cur(0), ar(new Pair<CIPH, VAL>[QUOTA]) {}
	MyMap(const MyMap<CIPH, VAL>&);
	~MyMap() { this->clear(); }
	MyMap<CIPH, VAL>& operator = (const MyMap<CIPH, VAL>&);
	VAL& operator[](const CIPH&); // l-value
	const VAL& operator[](const CIPH&) const; // r-value
	typedef Iter<CIPH, VAL> Iterator;
	bool empty() {
		if (cur > 0)
			return 0;
		else return 1;
	}
	int erase(const CIPH&);
	int clear();
	Iterator begin();
	Iterator end();
	Iterator find(const CIPH&) const;
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

template<class CIPH, class VAL>
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
		if (this->empty()) {
			ar[0].first = s;
			++cur;
			return ar[0].second;
		}
		if (s < ar[0].first) {
			for (int j = cur; j > 0; --j) {
				ar[j] = ar[j - 1];
			}
			ar[0].first = s;
			++cur;
			return ar[0].second;
		}
		if (s > ar[cur - 1].first) {
			ar[cur].first = s;
			++cur;
			return ar[cur - 1].second;
		}
		for (int j = 0; j < cur - 1; ++j) {
			if (ar[j].first < s && s < ar[j + 1].first) { // insert in position j+1
				for (int k = cur; k > j + 1; --k)
					ar[k] = ar[k - 1];
				ar[j + 1].first = s;
				++cur;
				return ar[j + 1].second;
			}
		}
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

template <class CIPH, class VAL>
int MyMap<CIPH, VAL>::erase(const CIPH& ciph) {
	int pos = getPos(ciph);
	if (pos != -1) {
		for (int i = pos; i < cur - 1; ++i) {
			ar[i] = ar[i + 1];
		}
		this->ar[cur - 1].second = nullptr;
		this->ar[cur - 1].first = "";
		--cur;
		return 0;
	}
	else
		return -1;
}

template <class CIPH, class VAL>
int MyMap<CIPH, VAL>::clear() {
	delete[] ar;
	return 0;
}

template <class CIPH, class VAL>
Iter<CIPH, VAL> MyMap<CIPH, VAL>::begin() {
	return Iter<CIPH, VAL>(this->ar);
}

template <class CIPH, class VAL>
Iter<CIPH, VAL> MyMap<CIPH, VAL>::end() {
	return Iter<CIPH, VAL>(this->ar + cur);
}

template <class CIPH, class VAL>
Iter<CIPH, VAL> MyMap<CIPH, VAL>::find(const CIPH& s) const {
	int i = getPos(s);
	if (i < 0)
		i = cur;
	return Iter<CIPH, VAL>(this->ar + i);
}

template <class CIPH, class VAL>
class Iter {
private:
	Pair<CIPH, VAL>* cur;
public:
	Iter() : cur(0) {}
	Iter(Pair<CIPH, VAL>* a) : cur(a) {}
	int operator!=(const Iter<CIPH, VAL>&)const;
	int operator==(const Iter<CIPH, VAL>&)const;
	Pair<CIPH, VAL>& operator*();
	Pair<CIPH, VAL>* operator->();
	Iter<CIPH, VAL>& operator ++();
	Iter<CIPH, VAL> operator ++(int);
};

template <class CIPH, class VAL>
int Iter<CIPH, VAL>::operator!=(const Iter<CIPH, VAL>& it) const {
	return cur != it.cur;
}

template <class CIPH, class VAL>
int Iter<CIPH, VAL>::operator==(const Iter<CIPH, VAL>& it)const {
	return cur == it.cur;
}

template<class CIPH, class VAL>
Pair<CIPH, VAL>& Iter<CIPH, VAL>::operator*() {
	return *cur;
}

template<class CIPH, class VAL>
Pair<CIPH, VAL>* Iter<CIPH, VAL>::operator->() {
	return cur;
}

template<class CIPH, class VAL>
Iter<CIPH, VAL>& Iter<CIPH, VAL>::operator++() {
	++cur;
	return *this;
}
template<class CIPH, class VAL>
Iter<CIPH, VAL> Iter<CIPH, VAL>::operator++(int) {
	Iter<CIPH, VAL> res(*this);
	++cur;
	return res;
}