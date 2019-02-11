//
//  VectorManipulator.h
//  lab-2
//
//  Created by Viktor Anashkin on 11/16/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef VectorManipulator_h
#define VectorManipulator_h

#include <vector>
#include "Complex.h"

class VectorManipulator {
public:
    static std::vector<Complex> add(std::vector<Complex>, std::vector<Complex>);
    static void print(std::vector<Complex>);
};

#endif /* VectorManipulator_h */
