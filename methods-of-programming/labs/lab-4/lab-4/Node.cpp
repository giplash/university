//
//  Node.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "Node.hpp"

template <class T>
Node<T>::Node() {
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
Node<T>::Node(T value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
Node<T>::Node(T value, Node<T> *left, Node<T> *right) {
    this->value = value;
    this->left = left;
    this->right = right;
}
