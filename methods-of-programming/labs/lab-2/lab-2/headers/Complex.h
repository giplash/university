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
    //добавить константы
    //переписать на комплексное число, проверить на совпадение
    friend ostream& operator << (ostream&, const Complex&);
    Complex& operator = (Complex number) {
        if (number.value[0] != value[0]) {
            value[0] = number.value[0];
        }
        if (number.value[1] != value[1]) {
            value[1] = number.value[1];
        }
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
