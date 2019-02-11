//
//  Dog.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/24/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Dog_h
#define Dog_h

#include <stdio.h>
#include <string>
#include <fstream>

class Dog {
public:
    std::string name;    
    friend std::ostream& operator << (std::ostream&, const Dog&);
    Dog();
    Dog(std::string);
    ~Dog(){};
};

#endif /* Dog_h */
