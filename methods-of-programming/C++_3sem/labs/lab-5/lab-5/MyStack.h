//
//  MyStack.hpp
//  lab-5
//
//  Created by Viktor Anashkin on 12/7/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h

#include <stdio.h>
#include "Stack.h"
#include <string>

class MyStack : public Stack {
private:
    time_t lastUsed;
    void updateLastUsed();
public:
    time_t getLastUsed();
    std::string getStringLastUsed();
    
    void push(int);
    int pop();
    int peek();
    
    int size();
    bool isEmpty();
    bool isFull();
};



#endif /* MyStack_h */
