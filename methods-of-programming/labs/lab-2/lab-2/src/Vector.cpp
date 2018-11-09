//
//  Vector.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 11/10/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <stdexcept>
#include "Vector.h"
using namespace std;

Vector::Vector() {
    cout << "Input dimension: ";
    cin >> this->dimension;
    fillFromConsole();
}

Vector::Vector(int dimension) {
    this->dimension = dimension;
    fillFromConsole();
}

Vector::Vector(vector<Complex> vector) {
    dimension = vector.size();
    for (int i = 0; i < dimension; i++) {
        value.push_back(vector[i]);
    }
}

Vector::~Vector() {}

void Vector::fillFromConsole() {
    cout << "Input coords:" << endl;
    for (int i = 0; i < dimension; i++) {
        cout << i + 1 << ") ";
        double real, imag;
        cin >> real >> imag;
        value.push_back(Complex(real, imag));
    }
}

void Vector::print() {
    for (int i = 0; i < dimension; i++) {
        cout << value[i] << endl;
    }
}

Vector addVectors(Vector a, Vector b) {
    if (a.dimension != b.dimension) {
        throw logic_error("We can't add vectors with different dimensions");
    }
    int dimension = a.dimension;
    vector<Complex> result;
    for (int i = 0; i < dimension; i++) {
        result.push_back(a.value[i] + b.value[i]);
    }
    return Vector(result);
}
