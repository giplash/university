//
//  Dog.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/24/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "Dog.h"
#include <string>
#include <fstream>

using namespace std;

Dog::Dog() {
    this->name = "";
}

Dog::Dog(string name) {
    this->name = name;
}

std::ostream& operator << (std::ostream& stream, const Dog& a){
    stream << a.name;
    return stream;
}
