//
//  Node.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>

template <class T>
class Node {
public:
    T value;
    Node<T> *right;
    Node<T> *left;
    
    Node();
    Node(T);
    ~Node() {};
};

#endif /* Node_h */
