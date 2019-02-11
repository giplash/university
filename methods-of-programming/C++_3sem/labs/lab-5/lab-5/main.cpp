//
//  main.cpp
//  lab-5
//
//  Created by Viktor Anashkin on 12/6/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include "Stack.h"
#include "MyStack.h"
using namespace std;

int main() {
    Stack* base;
    MyStack child;
    base = &child;
    
    base->push(5);
    cout << child.getStringLastUsed() << endl;
    usleep(1000000);
    base->pop();
    cout << child.getStringLastUsed() << endl;
    usleep(1000000);
    base->push(5);
    cout << child.getStringLastUsed() << endl;
    return 0;
    
}
