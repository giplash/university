//
//  ExtendedBinaryTreeTester.cpp
//  lab-3
//
//  Created by Viktor Anashkin on 11/9/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "ExtendedBinaryTreeTester.h"
#include <iostream>
using namespace std;

void ExtendedBinaryTreeTester::test() {
    cout << "--------------" << endl;
    cout << "test 1" << endl;
    ExtendedBinaryTree tree1;
    bool res1 = true;
    if (tree1.root != nullptr)
        res1 = false;
    if (tree1.depth() != 0)
        res1 = false;
    if (tree1.countMaxElements() != 0)
        res1 = false;
    if (tree1.has(5) != false)
        res1 = false;
    
    cout << "    " << (res1 ? "passed (ok)" : "not passed") << endl;
    
    cout << "--------------" << endl;
    cout << "test 2" << endl;
    ExtendedBinaryTree tree2;
    bool res2 = true;
    tree2.insert(10);
    tree2.insert(9);
    tree2.insert(11);
    tree2.insert(12);
    tree2.insert(10.5);
    if (tree2.root->value != 10)
        res2 = false;
    if (tree2.root->left->value != 9)
        res2 = false;
    if (tree2.root->right->value != 11)
        res2 = false;
    if (tree2.root->right->right->value != 12)
        res2 = false;
    if (tree2.root->right->left->value != 10.5)
        res2 = false;
    if (tree2.depth() != 3)
        res2 = false;
    if (tree2.countMaxElements() != 1)
        res2 = false;
    if (tree2.has(12) != true)
        res2 = false;
    cout << "    " << (res2 ? "passed (ok)" : "not passed") << endl;
    
    cout << "--------------" << endl;
    cout << "test 3" << endl;
    ExtendedBinaryTree tree3;
    bool res3 = true;
    tree3.insert(10);
    tree3.insert(9);
    tree3.insert(10);
    tree3.insert(12);
    tree3.insert(10);
    tree3.insert(12);
    tree3.insert(12);
    if (tree3.root->value != 10)
        res3 = false;
    if (tree3.root->left->value != 9)
        res3 = false;
    if (tree3.root->right->value != 10)
        res3 = false;
    if (tree3.root->right->right->value != 12)
        res3 = false;
    if (tree3.root->right->right->left->value != 10)
        res3 = false;
    if (tree3.root->right->right->right->value != 12)
        res3 = false;
    if (tree3.root->right->right->right->right->value != 12)
        res3 = false;
    if (tree3.depth() != 5)
        res3 = false;
    if (tree3.countMaxElements() != 3)
        res3 = false;
    double* array = tree3.toArray();
    if (array[0] != 9)
        res3 = false;
    if (array[1] != 10)
        res3 = false;
    if (array[2] != 10)
        res3 = false;
    if (array[3] != 10)
        res3 = false;
    if (array[4] != 12)
        res3 = false;
    if (array[5] != 12)
        res3 = false;
    if (array[6] != 12)
        res3 = false;
    cout << "    " << (res3 ? "passed (ok)" : "not passed") << endl;
    
    cout << "--------------" << endl;
    cout << "test 4" << endl;
    ExtendedBinaryTree tree4;
    bool res4 = true;
    tree4.fillFromFile("test.txt");
    if (tree4.root->value != 5)
        res4 = false;
    if (tree4.root->left->value != 4)
        res4 = false;
    if (tree4.root->right->value != 7)
        res4 = false;
    if (tree4.root->right->right->value != 8)
        res4 = false;
    if (tree4.root->left->left->value != 1)
        res4 = false;
    if (tree4.root->left->left->right->value != 2)
        res4 = false;
    if (tree4.root->right->right->right->value != 10)
        res4 = false;
    if (tree4.depth() != 4)
        res4 = false;
    cout << "    " << (res4 ? "passed (ok)" : "not passed") << endl;
    cout << "--------------" << endl;
}
