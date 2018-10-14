//
//  Complex.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 9/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Complex.h"

using namespace std;


double Complex::getReal() {
    return real;
}

double Complex::getImag() {
    return imag;
}


Complex operator + (Complex& a, double b){
    double real = a.getReal() + b;
    double imag = a.getImag();
    Complex temp(real, imag);
    return temp;
}

Complex operator + (Complex& a, Complex& b){
    double real = a.getReal() + b.getReal();
    double imag = a.getImag() + b.getImag();
    Complex temp(real, imag);
    return temp;
}

Complex operator - (Complex& a, double b){
    double real = a.getReal() - b;
    double imag = a.getImag();
    Complex temp(real, imag);
    return temp;
}

Complex operator - (Complex& a, Complex& b){
    double real = a.getReal() - b.getReal();
    double imag = a.getImag() - b.getImag();
    Complex temp(real, imag);
    return temp;
}

Complex operator * (Complex& a, double b){
    double real = a.getReal() * b;
    double imag = a.getImag() * b;
    Complex temp(real, imag);
    return temp;
}

Complex operator * (Complex& a, Complex& b){
    double real = a.getReal() * b.getReal() - a.getImag() * b.getImag();
    double imag = a.getReal() * b.getImag() + a.getImag() * b.getReal();
    Complex temp(real, imag);
    return temp;
}

Complex operator / (Complex& a, double b){
    double real = a.getReal() / b;
    double imag = a.getImag() / b;
    Complex temp(real, imag);
    return temp;
}

Complex operator / (Complex& a, Complex& b){
    Complex c(b.getReal(), -b.getImag());
    Complex numerator;
    numerator = a * c;
    double denominator = (b * c).getReal();
    Complex temp;
    temp = (numerator / denominator);
    return temp;
}


ostream& operator<<(ostream& stream,Complex& a){
    stream << a.real;
    a.imag < 0.0 ?
    stream << " - " <<  -a.imag << "i" :
    stream << " + " <<  a.imag << "i";
    return stream;
}

Complex::Complex() {
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(const Complex &number){
    real = number.real;
    imag = number.imag;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}
