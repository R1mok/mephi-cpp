#define _USE_MATH_DEFINES

#include "gtest/gtest.h"
#include "../lab2/Nephroid.h"
#include "../lab2/NephroidMethods.h"
#include <math.h>

TEST(NephroidConstructor, DefaultConstructor) {
    Prog2::Nephroid a1;
    ASSERT_EQ(1, a1.getR());
    ASSERT_EQ(1, a1.getT());
}

TEST(NephroidConstructor, InitConstructor) {
    Prog2::Nephroid a2(3);
    ASSERT_EQ(3, a2.getR());

    Prog2::Nephroid a3(3, 2);
    ASSERT_EQ(3, a3.getR());
    ASSERT_EQ(2, a3.getT());
}

TEST(NephroidConstructor, TestExecption) {
    ASSERT_ANY_THROW(Prog2::Nephroid(-1, 1));
    ASSERT_ANY_THROW(Prog2::Nephroid(1, -1));
}

TEST(NephroidMethods, Setters)
{
    Prog2::Nephroid a;
    double r = 3, t = 2;
    a.setR(r);
    a.setT(t);
    ASSERT_EQ(3, a.getR());
    ASSERT_EQ(2, a.getT());
}

TEST(NephroidMethods, Parameters) {
    Prog2::Nephroid a1;
    const double err = 0.000001;
    ASSERT_NEAR(12 * M_PI, a1.Area(), err);
    ASSERT_NEAR(24, a1.Length(), err);
    ASSERT_NEAR((3 * cos(M_PI / 180) + cos(3 * M_PI / 180)), a1.X_coord(), err);
    ASSERT_NEAR((3 * sin(3 * M_PI / 180) + sin(3 * M_PI / 180)), a1.Y_coord(), err);
    ASSERT_STREQ("(x^2 + y^2 - 4.00)^3 = 108.00*y^2", a1.frm());

    Prog2::Nephroid a2(2.3, 3.5);
    ASSERT_NEAR(3.5 * 3.5 * M_PI * 12, a2.Area(), err);
    ASSERT_NEAR(24 * 3.5, a2.Length(), err);
    ASSERT_NEAR((3 * 2.3 * cos(3.5 * M_PI / 180) + 2.3 * cos(3 * (3.5 * M_PI / 180))), a2.X_coord(), err);
    ASSERT_NEAR((3 * 2.3 * sin(3 * 3.5 * M_PI / 180) + sin(3 * (3.5 * M_PI) / 180)), a2.Y_coord(), err);
    ASSERT_STREQ("(x^2 + y^2 - 49.00)^3 = 16206.75*y^2", a2.frm());

    Prog2::Nephroid a3(1, 0);
    ASSERT_NEAR(0, a3.Area(), err);
    ASSERT_NEAR(0, a3.Length(), err);
    ASSERT_NEAR(3 * cos(0) + cos(0), a3.X_coord(), err);
    ASSERT_NEAR((3 * sin(0) + sin(0)), a3.Y_coord(), err);
    ASSERT_STREQ("x^2 + y^2 = 0", a3.frm());

}