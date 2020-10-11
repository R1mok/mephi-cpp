#define _USE_MATH_DEFINES
#ifndef _NEPHROID_H_
#define _NEPHROID_H_

#include <math.h>

namespace Prog2 {
	class Nephroid {			   
	public:
		// Конструкторы
		Nephroid() { r = 1;	t = 1; }
		Nephroid(double rad, double t1 = 1)	{
			if (rad < 0 || t1 < 0)
				throw std::exception("invalid radius or parameter t");
			r = rad, t = t1;
		}
		// сеттеры
		Nephroid& setR(double r0) {
			if (r0 < 0)
				throw std::exception("invalid radius");
			r = r0;
			return *this;
		}
		Nephroid& setT(double& t0) {
			if (t0 < 0)
				throw std::exception("invalid parameter t");
			t = t0;
			return *this; 
		} 
		// геттеры
		double getR() const{ return r; }
		double getT() const{ return t; }
		// другие методы
		double Length() { return 24.0 * t; } // длина кривой
		double Area() { return 12 * M_PI * t * t; } // площадь
		double X_coord() { return (3 * r * cos(t * M_PI / 180) + r * cos(3 * (t * M_PI / 180))); } // координата X
		double Y_coord() { return (3 * r * sin(3 * t * M_PI / 180) + sin(3 * (t * M_PI) / 180)); } // координата Y
		char* frm() const;// уравнение нефроиды (x^2 + y^2 - 4*t^2)^3 = 108*t^4*y^2
	private:
		double r, t; // радиус и параметр t
	};
}
#endif