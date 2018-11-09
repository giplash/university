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

void Complex::add(Complex number) {
    setReal(getReal() + number.getReal());
    setImag(getImag() + number.getImag());
}
void Complex::add(double number) {
    setReal(getReal() + number);
}

void Complex::subtract(Complex number) {
    setReal(getReal() - number.getReal());
    setImag(getImag() - number.getImag());
}
void Complex::subtract(double number) {
    setReal(getReal() - number);
}

void Complex::multiply(Complex number) {
    setReal(getReal() * number.getReal() - getImag() * number.getImag());
    setImag(getReal() * number.getImag() + getImag() * number.getReal());
}
void Complex::multiply(double number) {
    setReal(getReal() * number);
    setImag(getImag() * number);
}

void Complex::divide(Complex number) {
    Complex c(number.getReal(), -number.getImag());
    Complex numerator;
    numerator = *this * c;
    double denominator = (number * c).getReal();
    Complex temp;
    temp = (numerator / denominator);
    *this = temp;
}
void Complex::divide(double number) {
    setReal(getReal() / number);
    setImag(getImag() / number);
}

Complex Complex::operator + (double b){
    add(b);
    return *this;
}

Complex Complex::operator + (Complex& b){
    add(b);
    return *this;
}

Complex Complex::operator - (double b){
    subtract(b);
    return *this;
}

Complex Complex::operator - (Complex& b){
    subtract(b);
    return *this;
}

Complex Complex::operator * (double b){
    multiply(b);
    return *this;
}

Complex Complex::operator * (Complex& b){
    multiply(b);
    return *this;
}

Complex Complex::operator / (double b){
    divide(b);
    return *this;
}

Complex Complex::operator / (Complex& b){
    divide(b);
    return *this;
}


ostream& operator << (ostream& stream, const Complex& a){
    stream << a.value[0];
    a.value[1] < 0.0 ?
    stream << " - " <<  -a.value[1] << "i" :
    stream << " + " <<  a.value[1] << "i";
    return stream;
}

Complex& Complex::operator = (Complex number) {
    if (&(*this) == &number) {
        return *this;
    }
    if (number.value[0] != value[0]) {
        value[0] = number.value[0];
    }
    if (number.value[1] != value[1]) {
        value[1] = number.value[1];
    }
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
