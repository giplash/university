//
//  BinaryTree.cpp
//  lab-3
//
//  Created by Viktor Anashkin on 10/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>


BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insert(Node*& node, double value) {
    if (node == nullptr) {
        node = new Node(value);
        return;
    }
    if (value >= node->value) {
        insert(node->right, value);
    } else {
        insert(node->left, value);
    }
}

void BinaryTree::insert(double value) {
    insert(root, value);
}

bool BinaryTree::has(Node*& node, double value) {
    if (node == nullptr) {
        return false;
    }
    if (node->value == value) {
        return true;
    }
    if (value >= node->value) {
        return has(node->right, value);
    } else {
        return has(node->left, value);
    }
}

bool BinaryTree::has(double value) {
    return has(root, value);
}

void BinaryTree::destruct(Node* node) {
    if (node == nullptr) {
        return;
    }
    destruct(node->left);
    destruct(node->right);
    delete node;
}

BinaryTree::~BinaryTree() {
    destruct(root);
}
