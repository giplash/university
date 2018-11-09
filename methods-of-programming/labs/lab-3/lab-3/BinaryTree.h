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
protected:
    void insert(Node*&, double);
    bool has(Node*&, double);
    void destruct(Node*);
    Node* root;
public:
    void insert(double);
    bool has(double);
    BinaryTree();
    ~BinaryTree();
};


#endif /* BinaryTree_h */
