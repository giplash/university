//
//  Dog.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/24/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Dog_hpp
#define Dog_hpp

#include <stdio.h>
#include <string>

class Dog {
public:
    std::string name;
    
    bool isGreaterThan(Dog);
    bool isGreaterOrEqualTo(Dog);
    bool isEqualTo(Dog);
    
    Dog(std::string);
    ~Dog();
};

#endif /* Dog_hpp */
