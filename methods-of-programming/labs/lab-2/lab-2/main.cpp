//
//  main.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 9/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Complex.h"
#include "VectorManipulator.h"
#include "IVector.h"

using namespace std;


int main(int argc, const char * argv[]) {
    vector<Complex> a = IVector::create();
    vector<Complex> b = IVector::create();
    vector<Complex> c = VectorManipulator::add(a, b);
    cout << "Result: " << endl;
    VectorManipulator::print(c);
    return 0;
}
