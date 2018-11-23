//
//  ExtendedBinaryTree.hpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef ExtendedBinaryTree_hpp
#define ExtendedBinaryTree_hpp

#include <stdio.h>
#include <string>
#include "BinaryTree.hpp"
#include "Node.hpp"

template <class T>
class ExtendedBinaryTree : public BinaryTree<T> {
    void depth(Node<T>*, int, int&);
    void countMaxElements(Node<T>*, T&, int&);
    int toArray(Node<T>*, T*, int);
    void getAmount(Node<T>*, int&);
public:
    int depth();
    int countMaxElements();
    int getAmount();
    T* toArray();
    
    friend class ExtendedBinaryTreeTester;
};

#endif /* ExtendedBinaryTree_hpp */
