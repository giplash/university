//
//  Stack.h
//  lab-5
//
//  Created by Viktor Anashkin on 12/15/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <iostream>
using namespace std;

#define SIZE 10

class Stack {
    int *arr;
    int top;
    int capacity;
    
public:
    Stack(int size = SIZE);
    
    void virtual push(int);
    int pop();
    int virtual peek();
    
    int virtual size();
    bool virtual isEmpty();
    bool virtual isFull();
};



#endif /* Stack_h */
