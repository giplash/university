//
//  BinaryTree.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "BinaryTree.h"
#include "Node.h"
#include <iostream>
using namespace std;

template <class T, class C>
BinaryTree<T, C>::BinaryTree() {
    root = nullptr;
}

template <class T, class C>
void BinaryTree<T, C>::insert(Node<T>*& node, T value) {
    if (node == nullptr) {
        node = new Node<T>(value);
        return;
    }
//    if (value.isGreaterOrEqualTo(node->value)) {
    if (C::compare(value, node->value) >= 0) {
        insert(node->right, value);
    } else {
        insert(node->left, value);
    }
}

template <class T, class C>
void BinaryTree<T, C>::insert(T value) {
    insert(root, value);
}

template <class T, class C>
bool BinaryTree<T, C>::has(Node<T>*& node, T value) {
    if (node == nullptr) {
        return false;
    }
    if (C::compare(node->value, value) == 0) {
        return true;
    }
//    if (value.isGreaterOrEqualTo(node->value)) {
    if (C::compare(value, node->value) >= 0) {
        return has(node->right, value);
    } else {
        return has(node->left, value);
    }
}

template <class T, class C>
bool BinaryTree<T, C>::has(T value) {
    return has(root, value);
}

template <class T, class C>
void BinaryTree<T, C>::inOrder(Node<T>* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->value << ' ';
        inOrder(node->right);
    }
}

template <class T, class C>
void BinaryTree<T, C>::inOrder() {
    inOrder(this->root);
}

template <class T, class C>
void BinaryTree<T, C>::preOrder(Node<T>* node) {
    if (node != nullptr) {
        cout << node->value << ' ';
        inOrder(node->left);
        inOrder(node->right);
    }
}

template <class T, class C>
void BinaryTree<T, C>::preOrder() {
    inOrder(this->root);
}

template <class T, class C>
void BinaryTree<T, C>::postOrder(Node<T>* node) {
    if (node != nullptr) {
        inOrder(node->left);
        inOrder(node->right);
        cout << node->value << ' ';
    }
}

template <class T, class C>
void BinaryTree<T, C>::postOrder() {
    inOrder(this->root);
}


template <class T, class C>
void BinaryTree<T, C>::destruct(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    destruct(node->left);
    destruct(node->right);
    delete node;
}

template <class T, class C>
BinaryTree<T, C>::~BinaryTree() {
    destruct(root);
}
