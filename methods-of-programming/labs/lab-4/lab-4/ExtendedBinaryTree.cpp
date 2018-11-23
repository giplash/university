//
//  ExtendedBinaryTree.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "ExtendedBinaryTree.hpp"
#include "BinaryTree.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
void ExtendedBinaryTree<T>::depth(Node<T>* node, int currentDepth, int& maxDepth) {
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

template <class T>
int ExtendedBinaryTree<T>::depth() {
    if (BinaryTree<T>::root == nullptr) {
        return 0;
    }
    int maxDepth = 1;
    depth(BinaryTree<T>::root, maxDepth, maxDepth);
    return maxDepth;
}

template <class T>
void ExtendedBinaryTree<T>::countMaxElements(Node<T>* node, T& max, int& amount) {
    if (node == nullptr) return;
    if (node->value.isEqualTo(max)) {
        amount += 1;
    }
    if (node->value.isGreaterThan(max)) {
        max = node->value;
        amount = 1;
    }
    countMaxElements(node->left, max, amount);
    countMaxElements(node->right, max, amount);
}

template <class T>
int ExtendedBinaryTree<T>::countMaxElements() {
    if (BinaryTree<T>::root == nullptr) {
        return 0;
    }
    int amount = 0;
    T max = BinaryTree<T>::root->value;
    countMaxElements(BinaryTree<T>::root, max, amount);
    return amount;
}

template <class T>
void ExtendedBinaryTree<T>::getAmount(Node<T>* node, int& amount) {
    if (node == nullptr) return;
    amount += 1;
    getAmount(node->right, amount);
    getAmount(node->left, amount);
}

template <class T>
int ExtendedBinaryTree<T>::getAmount() {
    if (BinaryTree<T>::root == nullptr) {
        return 0;
    }
    int amount = 0;
    getAmount(BinaryTree<T>::root, amount);
    return amount;
}

template <class T>
int ExtendedBinaryTree<T>::toArray(Node<T>* node, T* array, int position) {
    if (node->left != nullptr) {
        position = toArray(node->left, array, position);
    }
    array[position++] = node->value;
    if (node->right != nullptr) {
        position = toArray(node->right, array, position);
    }
    return position;
}

template <class T>
T* ExtendedBinaryTree<T>::toArray() {
    int length = getAmount();
    T* res = new T(length);
    if (length == 0) {
        return res;
    }
    toArray(BinaryTree<T>::root, res, 0);
    return res;
}
