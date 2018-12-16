//
//  DogComparator.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 12/15/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include "DogComparator.h"
#include "Dog.h"

int DogComparator::compare(Dog a, Dog b) {
    if (a.name.size() == b.name.size()) {
        return 0;
    } else if (a.name.size() < b.name.size()) {
        return -1;
    } else  {
        return 1;
    }
}
