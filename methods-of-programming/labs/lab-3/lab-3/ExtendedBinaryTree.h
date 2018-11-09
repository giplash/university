//
//  ExtendedBinaryTree.hpp
//  lab-3
//
//  Created by Viktor Anashkin on 11/3/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef ExtendedBinaryTree_h
#define ExtendedBinaryTree_h

#include <stdio.h>
#include <string>
#include "BinaryTree.h"
#include "ExtendedBinaryTreeTester.h"

class ExtendedBinaryTree : public BinaryTree {
    void depth(Node*, int, int&);
    void countMaxElements(Node*, double&, int&);
    int toArray(Node*, double*, int);
    void getAmount(Node*, int&);
public:
    int depth();
    int countMaxElements();
    int getAmount();
    double* toArray();
    void fillFromFile(std::string);
    
    friend class ExtendedBinaryTreeTester;
};

#endif /* ExtendedBinaryTree_h */
