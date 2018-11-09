//
//  ExtendedBinaryTree.cpp
//  lab-3
//
//  Created by Viktor Anashkin on 11/3/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "ExtendedBinaryTree.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ExtendedBinaryTree::depth(Node* node, int currentDepth, int& maxDepth) {
    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }
    if (node->left != nullptr) {
        depth(node->left, currentDepth + 1, maxDepth);
    }
    if (node->right != nullptr) {
        depth(node->right, currentDepth + 1, maxDepth);
    }
}

int ExtendedBinaryTree::depth() {
    if (BinaryTree::root == nullptr) {
        return 0;
    }
    int maxDepth = 1;
    depth(BinaryTree::root, maxDepth, maxDepth);
    return maxDepth;
}

void ExtendedBinaryTree::countMaxElements(Node* node, double& max, int& amount) {
    if (node == nullptr) return;
    if (node->value == max) {
        amount += 1;
    }
    if (node->value > max) {
        max = node->value;
        amount = 1;
    }
    countMaxElements(node->left, max, amount);
    countMaxElements(node->right, max, amount);
}

int ExtendedBinaryTree::countMaxElements() {
    if (BinaryTree::root == nullptr) {
        return 0;
    }
    int amount = 0;
    double max = root->value;
    countMaxElements(BinaryTree::root, max, amount);
    return amount;
}

void ExtendedBinaryTree::getAmount(Node* node, int& amount) {
    if (node == nullptr) return;
    amount += 1;
    getAmount(node->right, amount);
    getAmount(node->left, amount);
}

int ExtendedBinaryTree::getAmount() {
    if (BinaryTree::root == nullptr) {
        return 0;
    }
    int amount = 0;
    getAmount(BinaryTree::root, amount);
    return amount;
}

int ExtendedBinaryTree::toArray(Node* node, double* array, int position) {
    if (node->left != nullptr) {
        position = toArray(node->left, array, position);
    }
    array[position++] = node->value;
    if (node->right != nullptr) {
        position = toArray(node->right, array, position);
    }
    return position;
}

double* ExtendedBinaryTree::toArray() {
    int length = getAmount();
    double* res = new double(length);
    if (length == 0) {
        return res;
    }
    toArray(BinaryTree::root, res, 0);
    return res;
}

void ExtendedBinaryTree::fillFromFile(std::string path) {
    if (path != "") {
        std::ifstream stream(path);
        double value;
        if (stream.is_open()) {
            while (!stream.eof()) {
                stream >> value;
                if (stream.eof()) break;
                BinaryTree::insert(value);
            }
            stream.close();
        } else {
            throw std::invalid_argument("received wrong path");
        }
    }
}



