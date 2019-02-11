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
#include "VectorFabric.h"

using namespace std;


int main(int argc, const char * argv[]) {
    double** data1 = new double*[4];
    double** data2 = new double*[4];
    
    for (int i = 0; i < 4; i++) {
        data1[i] = new double[2];
        data1[i][0] = i;
        data1[i][1] = -i;
        
        data2[i] = new double[2];
        data2[i][0] = 2 * i;
        data2[i][1] = 2 * (-i);
    }
    
    vector<Complex> a = VectorFabric::create(data1, 4);
    vector<Complex> b = VectorFabric::create(data2, 4);
    vector<Complex> c = VectorManipulator::add(a, b);
    cout << "Result: " << endl;
    VectorManipulator::print(c);
    return 0;
}
