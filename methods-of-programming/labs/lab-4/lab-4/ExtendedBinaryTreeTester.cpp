//
//  ExtendedBinaryTreeTester.cpp
//  lab-4
//
//  Created by Viktor Anashkin on 11/23/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include "ExtendedBinaryTreeTester.hpp"
#include <iostream>
#include "Dog.hpp"
#include "ExtendedBinaryTree.hpp"

using namespace std;

void ExtendedBinaryTreeTester::test() {
    Dog dog1("Viktor1");
    Dog dog2("Viktor12");
    Dog dog3("Viktor123");
    ExtendedBinaryTree<Dog> tree1;
    tree1.insert(dog1);
    tree1.insert(dog2);
    tree1.insert(dog3);
    cout << tree1.depth() << endl;
}
