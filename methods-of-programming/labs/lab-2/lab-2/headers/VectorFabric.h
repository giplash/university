//
//  VectorFiller.h
//  lab-2
//
//  Created by Viktor Anashkin on 11/16/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef VectorFabric_h
#define VectorFabric_h

#include <vector>
#include "Complex.h"

class VectorFabric {
public:
    static std::vector<Complex> create(double**, int);
};


#endif /* VectorFabric_h */
