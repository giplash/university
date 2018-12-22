//
//  MyStack.cpp
//  lab-5
//
//  Created by Viktor Anashkin on 12/7/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "MyStack.h"
#include <stack>
#include <ctime>
#include <string>

void MyStack::updateLastUsed() {
    lastUsed = time(NULL);
}

time_t MyStack::getLastUsed() {
    return lastUsed;
}

std::string MyStack::getStringLastUsed() {
    time_t rawtime = lastUsed;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    return asctime(timeinfo);
}
 
int MyStack::size(){
    updateLastUsed();
    return Stack::size();
}


bool MyStack::isEmpty(){
    updateLastUsed();
    return Stack::isEmpty();
}


int MyStack::peek(){
    updateLastUsed();
    return Stack::peek();
}


void MyStack::push(int val){
    updateLastUsed();
    return Stack::push(val);
}



int MyStack::pop(){
    updateLastUsed();
    return Stack::pop();
}


bool MyStack::isFull() {
    updateLastUsed();
    return Stack::isFull();
}
