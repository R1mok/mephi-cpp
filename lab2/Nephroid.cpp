#include <strstream>
#include <stdio.h>
#include <string.h>


#include "Nephroid.h"

namespace Prog2
{	// Реализация конструкторов
	/*Nephroid::Nephroid(double rad) :t(1)
	{
		if (r < 0)
			throw std::exception("invalid radius");
		r = rad;
	}
	Nephroid::Nephroid(double rad, double t) : r(rad)
	{
		if (r < 0)
			throw std::exception("invalid radius");
		r = rad;
	}*/
	// Реализация сеттеров
	Nephroid& Nephroid::setR(double r0)
	{
		if (r0 < 0)
		{
			throw std::exception("invalid radius");
		}
		r = r0;
		return *this;
	}
	char* Nephroid::frm() const // (x^2 + y^2 - 4*t*t)^3 = 108*t*t*t*t*y^2
	{
		const char* s1 = "(x^2 + y^2 )^3 = *y^2 \n";
		int l = strlen(s1) + 1;
		size_t Size = 20;
		char num[20];
		sprintf_s(num, 20, "%.2f", 4*t*t);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", 108*t*t*t*t);
		l += strlen(num);
		char* s = new char[l];
		int k = 0;
		if (t == 0)
		{
			sprintf_s(s, l, "x^2 + y^2 = 0");
		}
		else
		{
			double res = 4 * t * t;
			int count = sprintf_s(s, l, "(x^2 + y^2 - %.2f)^3", res);
			k = strlen(s);
			res = 108 * t * t * t * t;
			count = sprintf_s(s + k, l - k, " = %.2f*y^2", 108*t*t*t*t);
		}
		return s;
	}
}