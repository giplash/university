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

template <class T>
void MyStack<T>::updateLastUsed() {
    lastUsed = time(NULL);
}

template <class T>
time_t MyStack<T>::getLastUsed() {
    return lastUsed;
}

template <class T>
std::string MyStack<T>::getStringLastUsed() {
    time_t rawtime = lastUsed;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    return asctime(timeinfo);
}

template <class T>
size_t MyStack<T>::size(){
    updateLastUsed();
    return std::stack<T>::size();
}

template <class T>
bool MyStack<T>::empty(){
    updateLastUsed();
    return std::stack<T>::empty();
}

template <class T>
T& MyStack<T>::top(){
    updateLastUsed();
    return std::stack<T>::top();
}

template <class T>
void MyStack<T>::push(const T& val){
    updateLastUsed();
    return std::stack<T>::push(val);
}

template <class T>
void MyStack<T>::push(T&& val){
    updateLastUsed();
    return std::stack<T>::push(val);
}

template <class T>
void MyStack<T>::pop(){
    updateLastUsed();
    return std::stack<T>::pop();
}

template <class T>
void MyStack<T>::swap(std::stack<T>& val) noexcept{
    updateLastUsed();
    return std::stack<T>::swap(val);
}

template <class T>
void MyStack<T>::emplace(T&& val) {
    updateLastUsed();
    return std::stack<T>::emplace(val);
}
