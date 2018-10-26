//
//  Node.h
//  lab-3
//
//  Created by Viktor Anashkin on 10/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Node_h
#define Node_h

class Node {
public:
    double value;
    Node* left;
    Node* right;
    Node* parent;
    Node() {
        value = 0;
        this->parent = nullptr;
        this->right = nullptr;
        this->left = nullptr;
    }
    Node(double value) {
        this->value = value;
        this->parent = nullptr;
        this->right = nullptr;
        this->left = nullptr;
    }
    Node(double value, Node* parent) {
        this->value = value;
        this->parent = parent;
        this->right = nullptr;
        this->left = nullptr;
    }
    ~Node() {};
};


#endif /* Node_h */
