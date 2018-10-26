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
    max = NULL;
    maxAmount = 0;
    length = 0;
}

void BinaryTree::insertRecursive(Node* node, double value) {
    if (value < node->value) {
        if (node->left != nullptr) {
            insertRecursive(node->left, value);
        } else {
            node->left = new Node(value, node);
        }
    } else {
        if (node->right != nullptr) {
            insertRecursive(node->right, value);
        } else {
            node->right = new Node(value, node);
        }
    }
}

void BinaryTree::insert(double value) {
    length += 1;
    if (root == nullptr) {
        root = new Node(value);
        max = value;
        maxAmount = 1;
        return;
    }
    insertRecursive(root, value);
    if (value == max) {
        maxAmount += 1;
    }
    if (value > max) {
        max = value;
        maxAmount = 1;
    }
}

void BinaryTree::hasRecursive(Node* node, double value, bool& res) {
    if (res == true) return;
    if (node->value == value) {
        res = true;
        return;
    }
    if (node->left != nullptr) hasRecursive(node->left, value, res);
    if (node->right != nullptr) hasRecursive(node->right, value, res);
}

bool BinaryTree::has(double value) {
    if (root == nullptr) {
        return false;
    }
    bool res = false;
    hasRecursive(root, value, res);
    return res;
}

void BinaryTree::depthRecursive(Node* node, int currentDepth, int& maxDepth) {
    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }
    if (node->left != nullptr) {
        depthRecursive(node->left, currentDepth + 1, maxDepth);
    }
    if (node->right != nullptr) {
        depthRecursive(node->right, currentDepth + 1, maxDepth);
    }
}

int BinaryTree::depth() {
    if (root == nullptr) {
        return 0;
    }
    int depth = 1;
    depthRecursive(root, depth, depth);
    return depth;
}

int BinaryTree::countMaxElements() {
    return maxAmount;
}

int BinaryTree::toArrayRecursive(Node* node, double* array, int position) {
    if (node->left != nullptr) {
        position = toArrayRecursive(node->left, array, position);
    }
    array[position++] = node->value;
    if (node->right != nullptr) {
        position = toArrayRecursive(node->right, array, position);
    }
    return position;
}

double* BinaryTree::toArray() {
    double* res = new double(length);
    if (length == 0) {
        return res;
    }
    toArrayRecursive(root, res, 0);
    return res;
}

std::string BinaryTree::toString() {
    result = "";
    if (root == nullptr) {
        result = "";
        return result;
    }
    double* array = toArray();
    for (int i = 0; i < length; i++) {
        result += std::to_string(array[i]);
        result += "\n";
    }
    return result;
}

void BinaryTree::fillFromFile(std::string path) {
    if (path != "") {
        std::ifstream stream(path);
        double value;
        if (stream.is_open()) {
            while (!stream.eof()) {
                stream >> value;
                if (stream.eof()) break;
                insert(value);
            }
            stream.close();
        } else {
            throw std::invalid_argument( "received empty path" );
        }
    }
}
