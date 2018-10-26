//
//  BinaryTree.h
//  lab-3
//
//  Created by Viktor Anashkin on 10/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <string>
#include "Node.h"

class BinaryTree {
    void insertRecursive(Node*, double);
    void hasRecursive(Node*, double, bool&);
    void depthRecursive(Node*, int, int&);
    int toArrayRecursive(Node*, double*, int);
public:
    Node* root;
    double max;
    int maxAmount;
    int length;
    void insert(double);
    bool has(double);
    int depth();
    double* toArray();
    std::string toString();
    std::string result;
    int countMaxElements();
    void fillFromFile(std::string);
    BinaryTree();
    ~BinaryTree() {};
};


#endif /* BinaryTree_h */
