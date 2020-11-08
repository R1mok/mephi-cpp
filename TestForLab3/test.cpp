#include "pch.h"

#include "../lab3c/BigInt.cpp"

using namespace Prog3c;

TEST(ConstructorTest, Test1) {
    BigInt m;
    ASSERT_EQ('0', m.getDigit(0));
    ASSERT_EQ(m.getCount(), 1);
}
TEST(ConstructorTest, Test2) {
    const char* s = "42132";
    BigInt m(s);
    ASSERT_EQ('2', m.getDigit(0));
    ASSERT_EQ('3', m.getDigit(1));
    ASSERT_EQ('1', m.getDigit(2));
    ASSERT_EQ('2', m.getDigit(3));
    ASSERT_EQ('4', m.getDigit(4));
    ASSERT_EQ(m.getCount(), 5);
}
TEST(ConstructorTest, Test3) {
    long ll = 3213;
    BigInt m(ll);
    ASSERT_EQ(m.getDigit(0), '3');
    ASSERT_EQ(m.getDigit(1), '1');
    ASSERT_EQ(m.getDigit(2), '2');
    ASSERT_EQ(m.getDigit(3), '3');
    ASSERT_EQ(m.getCount(), 4);
}
TEST(IncreaseTest, Test1) {
    long ll = 6432;
    BigInt a(ll);
    a = a.increase();
    ASSERT_EQ('0', a.getDigit(0));
    ASSERT_EQ('2', a.getDigit(1));
    ASSERT_EQ('3', a.getDigit(2));
    ASSERT_EQ('4', a.getDigit(3));
    ASSERT_EQ('6', a.getDigit(4));
    ASSERT_EQ('0', a.getSign());
}
TEST(IncreaseTest, Test2) {
    const char* str = "-1321";
    BigInt b(str);
    b = b.increase();
    ASSERT_EQ(b.getDigit(0), '0');
    ASSERT_EQ(b.getDigit(1), '1');
    ASSERT_EQ(b.getDigit(2), '2');
    ASSERT_EQ(b.getDigit(3), '3');
    ASSERT_EQ(b.getDigit(4), '1');
    ASSERT_EQ(b.getSign(), '9');
}
TEST(IncreaseTest, Test3) {
    BigInt c;
    c = c.increase();
    ASSERT_EQ(c.getDigit(0), '0');
    ASSERT_EQ(c.getDigit(1), '1');
}
TEST(DecreaseTest, Test1) {
    const char* str = "-4213";
    BigInt a(str);
    a = a.decrease();
    ASSERT_EQ(a.getDigit(0), '1');
    ASSERT_EQ(a.getDigit(1), '2');
    ASSERT_EQ(a.getDigit(2), '4');
    ASSERT_EQ(a.getSign(), '9');
}
TEST(DecreaseTest, Test2) {
    BigInt b;
    b = b.decrease();
    ASSERT_EQ(b.getDigit(0), '0');
    ASSERT_EQ(b.getSign(), '0');
}
TEST(AdditionalCodeTest, Test1) {
    long ll = 3213;
    BigInt a(ll);
    a = ~a;
    ASSERT_EQ('3', a.getDigit(0));
    ASSERT_EQ('1', a.getDigit(1));
    ASSERT_EQ('2', a.getDigit(2));
    ASSERT_EQ('3', a.getDigit(3));
    ASSERT_EQ(a.getSign(), '0');
}
TEST(AdditionalCodeTest, Test2) {
    const char* str = "-4132";
    BigInt b(str);
    b = ~b;
    ASSERT_EQ(b.getDigit(0), '8');
    ASSERT_EQ(b.getDigit(1), '6');
    ASSERT_EQ(b.getDigit(2), '8');
    ASSERT_EQ(b.getDigit(3), '5');
    ASSERT_EQ(b.getSign(), '9');
}
TEST(AdditionTest, Test1) {
    long ll = 6341;
    BigInt a(ll);
    const char* str = "-3142";
    BigInt b(str);
    BigInt c;
    c = a + b;
    ASSERT_EQ(c.getDigit(0), '9');
    ASSERT_EQ(c.getDigit(1), '9');
    ASSERT_EQ(c.getDigit(2), '1');
    ASSERT_EQ(c.getDigit(3), '3');
    ASSERT_EQ(c.getSign(), '0');
}
TEST(AdditionTest, Test2) {
    long ll = 6341;
    BigInt a(ll);
    const char* str = "142";
    BigInt b(str);
    BigInt c;
    c = b + a;
    ASSERT_EQ(c.getDigit(0), '3');
    ASSERT_EQ(c.getDigit(1), '8');
    ASSERT_EQ(c.getDigit(2), '4');
    ASSERT_EQ(c.getDigit(3), '6');
}
TEST(AdditionTest, Test3) {
    long ll = -241;
    BigInt a(ll);
    const char* str = "1242";
    BigInt b(str);
    BigInt c;
    c = b + a;
    ASSERT_EQ(c.getDigit(0), '1');
    ASSERT_EQ(c.getDigit(1), '0');
    ASSERT_EQ(c.getDigit(2), '0');
    ASSERT_EQ(c.getDigit(3), '1');
    ASSERT_EQ(c.getSign(), '0');
}
TEST(AdditionTest, Test4) {
    long ll = -111;
    BigInt a(ll);
    const char* str = "124";
    BigInt b(str);
    BigInt c;
    c = b + a;
    ASSERT_EQ(c.getDigit(0), '3');
    ASSERT_EQ(c.getDigit(1), '1');
    ASSERT_EQ(c.getSign(), '0');
}
TEST(SubtractionTest, Test1) {
    long ll = -111;
    BigInt a(ll);
    const char* str = "234";
    BigInt b(str);
    BigInt c;
    c = a - b;
    ASSERT_EQ(c.getDigit(0), '5');
    ASSERT_EQ(c.getDigit(1), '4');
    ASSERT_EQ(c.getDigit(2), '3');
    ASSERT_EQ(c.getSign(), '9');
}
TEST(SubtractionTest, Test2) {
    long ll = 2731;
    BigInt a(ll);
    const char* str = "-2334";
    BigInt b(str);
    BigInt c;
    c = a - b;
    ASSERT_EQ(c.getDigit(0), '5');
    ASSERT_EQ(c.getDigit(1), '6');
    ASSERT_EQ(c.getDigit(2), '0');
    ASSERT_EQ(c.getDigit(3), '5');
    ASSERT_EQ(c.getSign(), '0');
}
TEST(SubtractionTest, Test3) {
    long ll = 2731;
    BigInt a(ll);
    const char* str = "1334";
    BigInt b(str);
    BigInt c;
    c = a - b;
    ASSERT_EQ(c.getDigit(0), '7');
    ASSERT_EQ(c.getDigit(1), '9');
    ASSERT_EQ(c.getDigit(2), '3');
    ASSERT_EQ(c.getDigit(3), '1');
    ASSERT_EQ(c.getSign(), '0');
}