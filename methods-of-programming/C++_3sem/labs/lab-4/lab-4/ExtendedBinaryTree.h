//
//  ExtendedBinaryTree.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef ExtendedBinaryTree_h
#define ExtendedBinaryTree_h

#include <stdio.h>
#include <string>
#include "BinaryTree.h"
#include "Node.h"

template <class T, class C>
class ExtendedBinaryTree : public BinaryTree<T, C> {
    void depth(Node<T>*, int, int&);
    void countMaxElements(Node<T>*, T&, int&);
    int toArray(Node<T>*, T*, int);
    void getAmount(Node<T>*, int&);
public:
    int depth();
    int countMaxElements();
    int getAmount();
    T* toArray();
};

#endif /* ExtendedBinaryTree_h */
