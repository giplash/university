//
//  Vector.h
//  lab-2
//
//  Created by Viktor Anashkin on 11/10/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include "Complex.h"
#include <vector>

class Vector {
    std::vector<Complex> value;
    int dimension;
    void fillFromConsole();
public:
    void print();
    Vector();
    Vector(int);
    Vector(vector<Complex>);
    ~Vector();
    
    friend Vector addVectors(Vector, Vector);
};

#endif /* Vector_h */
