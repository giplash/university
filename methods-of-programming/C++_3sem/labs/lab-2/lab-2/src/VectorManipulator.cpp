//
//  VectorManipulator.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 11/16/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <stdexcept>
#include <vector>
#include "VectorManipulator.h"
#include "Complex.h"
#include <iostream>

using namespace std;

std::vector<Complex> VectorManipulator::add(
                                            std::vector<Complex> vector1,
                                            std::vector<Complex> vector2
                                            ) {
    if (vector1.size() != vector2.size()) {
        throw std::invalid_argument( "received vectors with diferrent dimensions" );
    }
    size_t dimension = vector1.size();
    std::vector<Complex> res;
    for (int i = 0; i < dimension; i++) {
        res.push_back(vector1[i] + vector2[i]);
    }
    return res;
}

void VectorManipulator::print(std::vector<Complex> vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << i+1 << ") " << vector[i] << std::endl;
    }
}
