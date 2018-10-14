//
//  Complex.h
//  lab-2
//
//  Created by Viktor Anashkin on 9/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Complex_h
#define Complex_h
#include <iostream>

using namespace std;

class Complex {
    double real;
    double imag;
    
public:
    double getReal();
    double getImag();
    
    friend ostream& operator << (ostream&, Complex&);
    Complex& operator = (double a) {
        real = a;
        imag = 0;
        return *this;
    }
    Complex();
    Complex(const Complex &a);
    Complex(double, double);
    
    
};


Complex operator + (Complex&, double);
Complex operator + (Complex&, Complex&);
Complex operator - (Complex&, double);
Complex operator - (Complex&, Complex&);
Complex operator * (Complex&, double);
Complex operator * (Complex&, Complex&);
Complex operator / (Complex&, double);
Complex operator / (Complex&, Complex&);

#endif /* Complex_h */
