//
//  Node.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <class T>
class Node {
public:
    T value;
    Node<T> *right;
    Node<T> *left;
    
    Node();
    Node(T);    
    Node(T, Node<T>*, Node<T>*);
};

#endif /* Node_hpp */
