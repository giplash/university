//
//  BinaryTree.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "BinaryTree.hpp"
#include "Node.hpp"

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
void BinaryTree<T>::insert(Node<T>*& node, T value) {
    if (node == nullptr) {
        node = new Node<T>(value);
        return;
    }
    if (value.isGreaterOrEqualTo(node->value)) {
        insert(node->right, value);
    } else {
        insert(node->left, value);
    }
}

template <class T>
void BinaryTree<T>::insert(T value) {
    insert(root, value);
}

template <class T>
bool BinaryTree<T>::has(Node<T>*& node, T value) {
    if (node == nullptr) {
        return false;
    }
    if (node->value.isEqualTo(value)) {
        return true;
    }
    if (value.isGreaterOrEqualTo(node->value)) {
        return has(node->right, value);
    } else {
        return has(node->left, value);
    }
}

template <class T>
bool BinaryTree<T>::has(T value) {
    return has(root, value);
}

template <class T>
void BinaryTree<T>::destruct(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    destruct(node->left);
    destruct(node->right);
    delete node;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    destruct(root);
}
