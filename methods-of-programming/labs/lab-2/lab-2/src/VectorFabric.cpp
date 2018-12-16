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

std::vector<Complex> VectorFabric::create(double** data, int length) {
    std::vector<Complex> res;
    for (int i = 0; i < length; i++) {
        res.push_back(Complex(data[i][0], data[i][1]));
    }
    return res;
}
