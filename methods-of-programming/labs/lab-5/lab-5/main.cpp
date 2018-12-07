//
//  main.cpp
//  lab-5
//
//  Created by Viktor Anashkin on 12/6/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include "MyStack.h"
#include "MyStack.cpp"
#include <unistd.h>
using namespace std;

int main() {
    MyStack<int> test;
    test.push(5);
    cout << test.getStringLastUsed() << endl;
    usleep(1000000);
    test.push(6);
    cout << test.getStringLastUsed() << endl;
    usleep(1000000);
    test.pop();
    cout << test.getStringLastUsed() << endl;
    return 0;
    
}
