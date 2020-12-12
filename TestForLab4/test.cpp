#include "pch.h"
using namespace Prog4;
TEST(ConstructorTest, wDescriptor1) {
	wDescriptor w1;
	ASSERT_EQ(w1.getName(), "");
	ASSERT_EQ(w1.getCountry(), "");
	ASSERT_EQ(w1.getFirm(), "");
	ASSERT_EQ(w1.getType(), 'w');
	ASSERT_EQ(w1.getCost(), 0);
	ASSERT_EQ(w1.getCount(), 0);
	ASSERT_EQ(w1.getCountWholesale(), 0);
}
TEST(ConstructorTest, wDescriptor2) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	int count1 = 32, cost1 = 34;
	wDescriptor w2(name1, firm1, country1, count1, cost1, 423);
	ASSERT_EQ(w2.getName(), "NAME");
	ASSERT_EQ(w2.getCountry(), "COUNTRY");
	ASSERT_EQ(w2.getFirm(), "FIRM");
	ASSERT_EQ(w2.getType(), 'w');
	ASSERT_EQ(w2.getCost(), 34);
	ASSERT_EQ(w2.getCount(), 32);
	ASSERT_EQ(w2.getCountWholesale(), 423);
}
TEST(ConstructorTest, wDescriptor3) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	wDescriptor w3(name1, firm1, country1);
	ASSERT_EQ(w3.getName(), "NAME");
	ASSERT_EQ(w3.getCountry(), "COUNTRY");
	ASSERT_EQ(w3.getFirm(), "FIRM");
	ASSERT_EQ(w3.getType(), 'w');
	ASSERT_EQ(w3.getCost(), 0);
	ASSERT_EQ(w3.getCount(), 0);
	ASSERT_EQ(w3.getCountWholesale(), 0);
}
TEST(ConstructorTest, wDescriptor4) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	wDescriptor w4(name1, firm1, country1, 12, 43);
	ASSERT_EQ(w4.getName(), "NAME");
	ASSERT_EQ(w4.getCountry(), "COUNTRY");
	ASSERT_EQ(w4.getFirm(), "FIRM");
	ASSERT_EQ(w4.getType(), 'w');
	ASSERT_EQ(w4.getCost(), 43);
	ASSERT_EQ(w4.getCount(), 12);
	ASSERT_EQ(w4.getCountWholesale(), 0);
}
TEST(ConstructorTest, wDescriptor5) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	wDescriptor w2(name1, firm1, country1, 32, 12, 50);
	wDescriptor w1(w2);
	ASSERT_EQ(w1.getName(), "NAME");
	ASSERT_EQ(w1.getCountry(), "COUNTRY");
	ASSERT_EQ(w1.getFirm(), "FIRM");
	ASSERT_EQ(w1.getType(), 'w');
	ASSERT_EQ(w1.getCost(), 12);
	ASSERT_EQ(w1.getCount(), 32);
	ASSERT_EQ(w1.getCountWholesale(), 50);
}

TEST(ConstructorTest, rDescriptor1) {
	rDescriptor r1;
	ASSERT_EQ(r1.getName(), "");
	ASSERT_EQ(r1.getCountry(), "");
	ASSERT_EQ(r1.getFirm(), "");
	ASSERT_EQ(r1.getType(), 'r');
	ASSERT_EQ(r1.getCost(), 0);
	ASSERT_EQ(r1.getCount(), 0);
	ASSERT_EQ(r1.getAllowance(), 0);
}
TEST(ConstructorTest, rDescriptor2) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	int count1 = 32, cost1 = 34;
	rDescriptor r2(name1, firm1, country1, count1, cost1, 423);
	ASSERT_EQ(r2.getName(), "NAME");
	ASSERT_EQ(r2.getCountry(), "COUNTRY");
	ASSERT_EQ(r2.getFirm(), "FIRM");
	ASSERT_EQ(r2.getType(), 'r');
	ASSERT_EQ(r2.getCost(), 34);
	ASSERT_EQ(r2.getCount(), 32);
	ASSERT_EQ(r2.getAllowance(), 423);
}
TEST(ConstructorTest, rDescriptor3) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	rDescriptor r3(name1, firm1, country1);
	ASSERT_EQ(r3.getName(), "NAME");
	ASSERT_EQ(r3.getCountry(), "COUNTRY");
	ASSERT_EQ(r3.getFirm(), "FIRM");
	ASSERT_EQ(r3.getType(), 'r');
	ASSERT_EQ(r3.getCost(), 0);
	ASSERT_EQ(r3.getCount(), 0);
	ASSERT_EQ(r3.getAllowance(), 100);
}
TEST(ConstructorTest, rDescriptor4) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	rDescriptor r4(name1, firm1, country1, 12, 43);
	ASSERT_EQ(r4.getName(), "NAME");
	ASSERT_EQ(r4.getCountry(), "COUNTRY");
	ASSERT_EQ(r4.getFirm(), "FIRM");
	ASSERT_EQ(r4.getType(), 'r');
	ASSERT_EQ(r4.getCost(), 43);
	ASSERT_EQ(r4.getCount(), 12);
	ASSERT_EQ(r4.getAllowance(), 100);
}
TEST(ConstructorTest, rDescriptor5) {
	std::string name1 = "NAME", country1 = "COUNTRY", firm1 = "FIRM";
	rDescriptor r2(name1, firm1, country1, 32, 12, 200);
	rDescriptor r1(r2);
	ASSERT_EQ(r1.getName(), "NAME");
	ASSERT_EQ(r1.getCountry(), "COUNTRY");
	ASSERT_EQ(r1.getFirm(), "FIRM");
	ASSERT_EQ(r1.getType(), 'r');
	ASSERT_EQ(r1.getCost(), 12);
	ASSERT_EQ(r1.getCount(), 32);
	ASSERT_EQ(r1.getAllowance(), 200);
}
TEST(ConstructorTest, Table1) {
	Table a;
	ASSERT_EQ(a.getN(), 0);
}
TEST(TableAddTest, Table1) {
	Table a;
	rDescriptor r1("namer", "countryr", "firmr", 32, 42, 10);
	wDescriptor w1("namew", "countryw", "firmw", 32, 45, 100);
	a.add(r1);
	a.add(w1);
	ASSERT_EQ(a.find(get_md5(r1.getName())), &r1);
	ASSERT_EQ(a.find(get_md5(w1.getName())), &w1);
}
TEST(TableDelTest, Table1) {
	Table a;
	rDescriptor r1("namer", "countryr", "firmr", 32, 42, 10);
	wDescriptor w1("namew", "countryw", "firmw", 32, 45, 100);
	a.add(r1);
	a.add(w1);
	a.del(r1.getName());

	a.add(r1);
	ASSERT_EQ(a.find(get_md5(r1.getName())), &r1);
}
TEST(SaleTest, rDescriptor1) {
	int count = 21, cost = 42, allowance = 120;
	rDescriptor r1("namer", "countryr", "firmr", count, cost, allowance);
	ASSERT_EQ(r1.sale(10), 504);
}
TEST(SaleTest, wDescriptor1) {
	int count = 21, cost = 42, countWholesale = 120;
	wDescriptor w1("namew", "countryw", "firmw", count, cost, countWholesale);
	ASSERT_EQ(w1.sale(5), 25200);
}
TEST(MyMapTest, Constructor) {
	MyMap<std::string, descriptor*> map;
	ASSERT_EQ(map.empty(), 1);
	wDescriptor w1("name1", "firm1", "country1", 41, 32, 321);
	map[get_md5(w1.getName())] = &w1;
	ASSERT_EQ(map.empty(), 0);
}
TEST(MyMapTest, Insert1) {
	MyMap<std::string, descriptor*> map;
	wDescriptor w1("name1", "firm1", "country1", 32, 12, 521);
	rDescriptor r1("name2", "firm2", "country2", 42, 52, 123);
	descriptor* w = &w1;
	Iter < std::string, descriptor*> it;
	map[get_md5(w1.getName())] = &w1;
	map[get_md5(r1.getName())] = &r1;
	it = map.find(get_md5(w1.getName()));
	ASSERT_EQ(it->first, get_md5(w1.getName()));
	ASSERT_EQ(it->second, &w1);
}
TEST(MyMapTest, Insert2) {
	MyMap<std::string, descriptor*> map;
	wDescriptor w1("name1", "firm1", "country1", 41, 32, 321);
	rDescriptor r1("name2", "firm2", "country2", 32, 12, 521);
	descriptor* r = &r1;
	Iter < std::string, descriptor*> it;
	map[get_md5(r1.getName())] = &r1;
	it = map.find(get_md5(r1.getName()));
	ASSERT_EQ(it->first, get_md5(r1.getName()));
	ASSERT_EQ(it->second, &r1);
}
TEST(MyMapTest, Delete1) {
	MyMap<std::string, descriptor*> map;
	wDescriptor w1("name1", "firm1", "country1", 41, 32, 321);
	rDescriptor r1("name2", "firm2", "country2", 32, 12, 521);
	map[get_md5(r1.getName())] = &r1;
	map[get_md5(w1.getName())] = &w1;
	ASSERT_EQ(map.erase(get_md5(r1.getName())), 0);
	ASSERT_EQ(map.erase(get_md5(w1.getName())), 0);
}

TEST(MyMapTest, Value1) {
	MyMap<std::string, descriptor*> map;
	wDescriptor w1("name1", "firm1", "country1", 41, 32, 321);
	rDescriptor r1("name2", "firm2", "country2", 32, 12, 521);
	map[get_md5(r1.getName())] = &r1;
	map[get_md5(w1.getName())] = &w1;
	descriptor* r2;
	r2 = map[get_md5(r1.getName())];
	ASSERT_EQ(r2->getName(), r1.getName());
	ASSERT_EQ(r2->getType(), r1.getType());
}