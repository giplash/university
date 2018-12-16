//
//  ExtendedBinaryTreeTester.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include "ExtendedBinaryTreeTester.h"
#include "ExtendedBinaryTreeTester.h"
#include "Node.h"
#include "Node.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "ExtendedBinaryTree.h"
#include "ExtendedBinaryTree.cpp"
#include "Dog.h"
#include "DogComparator.h"

using namespace std;

void ExtendedBinaryTreeTester::test() {
    Dog dog1("1");
    Dog dog2("22");
    Dog dog3("333");
    Dog dog4("4444");
    Dog dog5("5555");
    Dog dog6("6666");
    Dog dog7("777");
    
    ExtendedBinaryTree<Dog, DogComparator> tree;
    cout << (tree.depth() == 0 ? "yes" : "no") << endl;
    
    tree.insert(dog1);
    tree.insert(dog2);
    tree.insert(dog3);
    tree.insert(dog4);
    tree.insert(dog5);
    
    cout << (tree.depth() == 5 ? "yes" : "no") << endl;
    cout << (tree.countMaxElements() == 2 ? "yes" : "no") << endl;
    
    
    tree.insert(dog6);
    tree.insert(dog7);
    
    cout << (tree.depth() == 6 ? "yes" : "no") << endl;
    cout << (tree.countMaxElements() == 3 ? "yes" : "no") << endl;
    
    tree.inOrder();
    
    
}
