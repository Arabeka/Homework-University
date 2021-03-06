#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class TComplex {
	double Re;    
	double Im; 
public:   
	TComplex(double x, double y) :Re(x), Im(y) { }   
	TComplex(TComplex& z) { Re = z.Re; Im = z.Im; }    
	~TComplex() {}    void print();   
	TComplex operator+(const TComplex& z)  // Додавання    
	{        TComplex w(0,0);        w.Re = Re+z.Re;        w.Im = Im+z.Im;        
	printf("Operator + \n");        return w;    }    TComplex operator-(const TComplex& z)  // Вирахування    
	{        TComplex w(0,0);        w.Re = Re-z.Re;        w.Im = Im-z.Im;        
	printf("Operator - \n");        return w;    }    TComplex operator*(const TComplex& z)  // Множення    
	{        TComplex w(0,0);        w.Re = Re*z.Re-Im*z.Im;        w.Im = Re*z.Im+Im*z.Re;       
	printf("Operator * \n");        return w;    }    TComplex operator-()            // Унарний мінус   
	{        Re = -Re;        Im = -Im;        printf("Unary operator - \n");        
	return *this;    }    TComplex operator~()            // Сполучене число    
	{        TComplex w(0,0);        w.Re = Re;        w.Im = -Im;        printf("Unary operator ~ \n");       
	return w;    }    TComplex operator/(TComplex& z)    {        
		TComplex w(0,0);       
	w=(*this)*(~z);        w.Re = w.Re/modul2(z);        w.Im = w.Im/modul2(z);       
	printf("Operator / \n");        return w;    }    double modul2(const TComplex& z)   
	{ return z.Re*z.Re+z.Im*z.Im;    } };
		int main() { TComplex u(1, 1), v(2, 2), z(0, 0);   
		z = (u + v)*u / v;    z.print();    return 0; }
	void TComplex::print() { printf("%lf + i*%lf\n", Re, Im); }
