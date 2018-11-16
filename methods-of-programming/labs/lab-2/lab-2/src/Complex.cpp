//
//  Complex.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 9/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Complex.h"

using namespace std;


double Complex::getReal() {
    return value[0];
}

double Complex::getImag() {
    return value[1];
}

void Complex::setReal(double value) {
    this->value[0] = value;
}

void Complex::setImag(double value) {
    this->value[1] = value;
}

Complex Complex::add(Complex number) {
    Complex res;
    res.setReal(getReal() + number.getReal());
    res.setImag(getImag() + number.getImag());
    return res;
}
Complex Complex::add(double number) {
    Complex res;
    res.setReal(getReal() + number);
    res.setImag(getImag());
    return res;
}

Complex Complex::subtract(Complex number) {
    Complex res;
    res.setReal(getReal() - number.getReal());
    res.setImag(getImag() - number.getImag());
    return res;
}
Complex Complex::subtract(double number) {
    Complex res;
    res.setReal(getReal() - number);
    res.setImag(getImag());
    return res;
}

Complex Complex::multiply(Complex number) {
    Complex res;
    res.setReal(getReal() * number.getReal() - getImag() * number.getImag());
    res.setImag(getReal() * number.getImag() + getImag() * number.getReal());
    return res;
}
Complex Complex::multiply(double number) {
    Complex res;
    res.setReal(getReal() * number);
    res.setImag(getImag() * number);
    return res;
}

Complex Complex::divide(Complex number) {
    Complex c(number.getReal(), -number.getImag());
    Complex numerator;
    numerator = *this * c;
    double denominator = (number * c).getReal();
    Complex res;
    res = (numerator / denominator);
    return res;
}
Complex Complex::divide(double number) {
    if (number == 0) {
        throw std::invalid_argument( "we can't divide by 0" );
    }
    Complex res;
    res.setReal(getReal() / number);
    res.setImag(getImag() / number);
    return res;
}

Complex Complex::operator + (double b){
    return add(b);
}

Complex Complex::operator + (Complex& b){
    return add(b);
}

Complex Complex::operator - (double b){
    return subtract(b);
}

Complex Complex::operator - (Complex& b){
    return subtract(b);
}

Complex Complex::operator * (double b){
    return multiply(b);
}

Complex Complex::operator * (Complex& b){
    return multiply(b);
}

Complex Complex::operator / (double b){
    return divide(b);
}

Complex Complex::operator / (Complex& b){
    return divide(b);
}


ostream& operator << (ostream& stream, const Complex& a){
    stream << a.value[0];
    // add manipulator
    stream << showpos << a.value[1] << "i";
    return stream;
}

Complex& Complex::operator = (Complex number) {
    if (&(*this) == &number) {
        return *this;
    }
    value[0] = number.value[0];
    value[1] = number.value[1];
    return *this;
}

Complex::Complex() {
    value = new double(2);
    setReal(0.0);
    setImag(0.0);
}

Complex::Complex(const Complex &number){
    value = new double(2);
    setReal(number.value[0]);
    setImag(number.value[1]);
}

Complex::Complex(double real, double imag) {
    value = new double(2);
    setReal(real);
    setImag(imag);
}
