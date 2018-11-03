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
    void insert(Node*, double);
    void has(Node*, double, bool&);
public:
    Node* root;
    void insert(double);
    bool has(double);
    BinaryTree();
    ~BinaryTree();
};


#endif /* BinaryTree_h */
