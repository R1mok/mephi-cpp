#ifndef _NEPHROID_H_
#define _NEPHROID_H_

//#include <gtest\gtest_prod.h>

#include <math.h>

namespace Prog2
{
	class Nephroid 
	{			   
	private:
		double r, t; // радиус и параметр t
	public:
		// Конструкторы
		Nephroid() :r(0) {}
		Nephroid(double rad) : r(rad) {}
		Nephroid(double rad, double t) : r(rad), t(t) {}
		// сеттеры
		Nephroid& setR(double r);
		Nephroid& setT(double &t0) { t = t0; return *this; }
		// геттеры
		double getR() const{ return r; }
		double getT() const{ return t; }
		// другие методы
		double Length() { return 24.0 * t; } // длина кривой
		double Area() { return 12 * 3.1415 * t * t; } // площидь
		//double Сurvature() { return abs(3 * r * cos(t * 3.1415 / 180)); } // кривизна

		double X_coord() { return (3 * r * cos(t * 3.1415 / 180) + r * cos(3 * (t * 3.1415 / 180))); } // координата X
		double Y_coord() { return (3 * r * sin(3 * t * 3.1415 / 180) + sin(3 * (t * 3.1415) / 180)); } // координата Y
		char* frm() const;// уравнение нефроиды (x^2 + y^2 - 4*t^2)^3 = 108*t^4*y^2
	};
}
#endif

