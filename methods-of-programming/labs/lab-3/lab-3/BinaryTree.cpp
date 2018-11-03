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

void BinaryTree::insert(Node* node, double value) {
    if (value < node->value) {
        if (node->left != nullptr) {
            insert(node->left, value);
        } else {
            node->left = new Node(value);
        }
    } else {
        if (node->right != nullptr) {
            insert(node->right, value);
        } else {
            node->right = new Node(value);
        }
    }
}

void BinaryTree::insert(double value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    insert(root, value);
}

void BinaryTree::has(Node* node, double value, bool& res) {
    if (res == true) return;
    if (node->value == value) {
        res = true;
        return;
    }
    if (node->left != nullptr) has(node->left, value, res);
    if (node->right != nullptr) has(node->right, value, res);
}

bool BinaryTree::has(double value) {
    if (root == nullptr) {
        return false;
    }
    bool res = false;
    has(root, value, res);
    return res;
}

BinaryTree::~BinaryTree() {
    delete root;
}
