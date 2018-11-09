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
    double* value;
public:
    double getReal();
    double getImag();
    void setReal(double);
    void setImag(double);
    
    void add(Complex);
    void add(double);
    void subtract(Complex);
    void subtract(double);
    void multiply(Complex);
    void multiply(double);
    void divide(Complex);
    void divide(double);
    
    friend ostream& operator << (ostream&, const Complex&);
    Complex& operator = (Complex);
    Complex operator + (double);
    Complex operator + (Complex&);
    Complex operator - (double);
    Complex operator - (Complex&);
    Complex operator * (double);
    Complex operator * (Complex&);
    Complex operator / (double);
    Complex operator / (Complex&);
    
    Complex();
    Complex(const Complex &a);
    Complex(double, double);
    
    
};



#endif /* Complex_h */
