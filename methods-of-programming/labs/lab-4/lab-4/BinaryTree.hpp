//
//  BinaryTree.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include "Node.hpp"

template <class T>
class BinaryTree {
protected:
    void insert(Node<T>*&, T);
    bool has(Node<T>*&, T);
    void destruct(Node<T>*);
    Node<T>* root;
public:
    void insert(T);
    bool has(T);
    BinaryTree();
    ~BinaryTree();
};

#endif /* BinaryTree_hpp */
