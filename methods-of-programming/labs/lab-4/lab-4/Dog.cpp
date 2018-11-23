//
//  Dog.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/24/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "Dog.hpp"
#include <string>

using namespace std;

Dog::Dog(string name) {
    this->name = name;
}

bool Dog::isEqualTo(Dog dog) {
    return dog.name.length() == name.length();
}

bool Dog::isGreaterThan(Dog dog) {
    return name.length() > dog.name.length();
}

bool Dog::isGreaterOrEqualTo(Dog dog) {
    return name.length() >= dog.name.length();
}
