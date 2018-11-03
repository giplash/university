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

Complex operator + (Complex& a, double b){
    a.add(b);
    return a;
}

Complex operator + (Complex& a, Complex& b){
    a.add(b);
    return a;
}

Complex operator - (Complex& a, double b){
    a.subtract(b);
    return a;
}

Complex operator - (Complex& a, Complex& b){
    a.subtract(b);
    return a;
}

Complex operator * (Complex& a, double b){
    a.multiply(b);
    return a;
}

Complex operator * (Complex& a, Complex& b){
    a.multiply(b);
    return a;
}

Complex operator / (Complex& a, double b){
    a.divide(b);
    return a;
}

Complex operator / (Complex& a, Complex& b){
    a.divide(b);
    return a;
}


ostream& operator << (ostream& stream, const Complex& a){
    stream << a.value[0];
    a.value[1] < 0.0 ?
    stream << " - " <<  -a.value[1] << "i" :
    stream << " + " <<  a.value[1] << "i";
    return stream;
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
