//
//  ExtendedBinaryTree.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "ExtendedBinaryTree.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"

using namespace std;

template <class T, class C>
void ExtendedBinaryTree<T, C>::depth(Node<T>* node, int currentDepth, int& maxDepth) {
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

template <class T, class C>
int ExtendedBinaryTree<T, C>::depth() {
    if (BinaryTree<T, C>::root == nullptr) {
        return 0;
    }
    int maxDepth = 1;
    depth(BinaryTree<T, C>::root, maxDepth, maxDepth);
    return maxDepth;
}

template <class T, class C>
void ExtendedBinaryTree<T, C>::countMaxElements(Node<T>* node, T& max, int& amount) {
    if (node == nullptr) return;
//    if (node->value.isEqualTo(max)) {
    if (C::compare(node->value, max) == 0) {
        amount += 1;
    }
//    if (node->value.isGreaterThan(max)) {
    if (C::compare(node->value, max) > 0) {
        max = node->value;
        amount = 1;
    }
    countMaxElements(node->left, max, amount);
    countMaxElements(node->right, max, amount);
}

template <class T, class C>
int ExtendedBinaryTree<T, C>::countMaxElements() {
    if (BinaryTree<T, C>::root == nullptr) {
        return 0;
    }
    int amount = 0;
    T max = BinaryTree<T, C>::root->value;
    countMaxElements(BinaryTree<T, C>::root, max, amount);
    return amount;
}

template <class T, class C>
void ExtendedBinaryTree<T, C>::getAmount(Node<T>* node, int& amount) {
    if (node == nullptr) return;
    amount += 1;
    getAmount(node->right, amount);
    getAmount(node->left, amount);
}

template <class T, class C>
int ExtendedBinaryTree<T, C>::getAmount() {
    if (BinaryTree<T, C>::root == nullptr) {
        return 0;
    }
    int amount = 0;
    getAmount(BinaryTree<T, C>::root, amount);
    return amount;
}

template <class T, class C>
int ExtendedBinaryTree<T, C>::toArray(Node<T>* node, T* array, int position) {
  if (node->left != nullptr) {
      position = toArray(node->left, array, position);
  }
  array[position++] = node->value;
  if (node->right != nullptr) {
      position = toArray(node->right, array, position);
  }
  return position;
}

template <class T, class C>
T* ExtendedBinaryTree<T, C>::toArray() {
  int length = getAmount();
  T* res = new T(length);
  if (length == 0) {
      return res;
  }
  toArray(BinaryTree<T, C>::root, res, 0);
    return res;
}
