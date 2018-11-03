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
    Node() {
        value = 0;
        this->right = nullptr;
        this->left = nullptr;
    }
    Node(double value) {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
    }
    ~Node() {
        delete left;
        delete right;
    };
};


#endif /* Node_h */
