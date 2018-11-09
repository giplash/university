//
//  main.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 9/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include "Vector.h"
using namespace std;


int main(int argc, const char * argv[]) {
    Vector a;
    Vector b;
    Vector c = addVectors(a, b);
    c.print();
    return 0;
}
