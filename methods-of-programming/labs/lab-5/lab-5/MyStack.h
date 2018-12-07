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
#include <stack>
#include <string>

template <class T>
class MyStack : public std::stack<T> {
private:
    time_t lastUsed;
    void updateLastUsed();
public:
    time_t getLastUsed();
    std::string getStringLastUsed();
    size_t size();
    bool empty();
    T& top();
    void push(const T&);
    void push(T&&);
    void pop();
    void swap(std::stack<T>&) noexcept;
    void emplace(T&&);
};



#endif /* MyStack_h */
