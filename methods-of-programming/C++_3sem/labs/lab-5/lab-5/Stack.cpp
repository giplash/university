//
//  Stack.cpp
//  lab-5
//
//  Created by Viktor Anashkin on 12/15/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack OverFlow. Program Terminated\n";
        exit(EXIT_FAILURE);
    }
    
    cout << "from Stack" << endl;
    arr[++top] = x;
}


int Stack::pop() {
    if (isEmpty()) {
        cout << "UnderFlow. Program Terminated\n";
        exit(EXIT_FAILURE);
    }
    
    cout << "from Stack" << endl;
    return arr[top--];
}


int Stack::peek() {
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}


int Stack::size() {
    return top + 1;
}


bool Stack::isEmpty() {
    return top == -1;
}


bool Stack::isFull() {
    return top == capacity - 1;
}
