//
//  VectorFiller.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 11/16/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "VectorFabric.h"
#include "Complex.h"

using namespace std;

std::vector<Complex> VectorFabric::create() {
    std::vector<Complex> res;
    int dimension;
    cout << "Input vector's dimension: ";
    cin >> dimension;
    cout << "Input coords:" << endl;
    for (int i = 0; i < dimension; i++) {
        cout << i + 1 << ") ";
        double real, imag;
        cin >> real >> imag;
        res.push_back(Complex(real, imag));
    }
    return res;
}
