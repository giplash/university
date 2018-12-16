//
//  BinaryTree.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include "Node.h"

template <class T, class C>
class BinaryTree {
protected:
    void insert(Node<T>*&, T);
    bool has(Node<T>*&, T);
    void destruct(Node<T>*);
    void preOrder(Node<T>*);
    void inOrder(Node<T>*);
    void postOrder(Node<T>*);
    Node<T>* root;
public:
    void insert(T);
    bool has(T);
    void preOrder();
    void inOrder();
    void postOrder();
    BinaryTree();
    ~BinaryTree();
};

#endif /* BinaryTree_h */
