//
//  main.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/2/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "StudentList.h"
#include "iStudentList.h"

using namespace std;

void showMenu(StudentList);

int main(int argc, const char * argv[]) {
    try {
        StudentList list = iStudentList::readData("неправильный путь");
    } catch (const ifstream::failure& e) {
        cout << e.what() << endl;
    }
    
    try {
        StudentList list = iStudentList::readData("data.txt");
        showMenu(list);
    } catch (const ifstream::failure& e) {
        cout << e.what() << endl;
        exit(1);
    }
    return 0;
}

void showMenu(StudentList list) {
    int choice;
    char faculty[30];
    while(1) {
        cout << endl;
        cout << "1 - write all" << endl;
        cout << "2 - write by year" << endl;
        cout << "3 - write by faculty" << endl;
        cout << "4 - write by course" << endl;
        cout << "else exit" << endl;
        cout << endl;
        cin >> choice;
        int course;
        int year;
        switch (choice) {
            case 1:
            {
                try {
                    list.writeRes("res.txt");
                } catch (const ifstream::failure& e) {
                    cout << e.what() << endl;
                    exit(1);
                }
                break;
            }
            case 2:
            {
                cout << "Input year" << endl;
                cin >> year;
                cout << endl;
                StudentList newList = list.filterByYear(year);
                try {
                    newList.writeRes("res.txt");
                } catch (const ifstream::failure& e) {
                    cout << e.what() << endl;
                    exit(1);
                }
                break;
            }
            case 3:
            {
                cout << "Input faculty" << endl;
                cin >> faculty;
                cout << endl;
                StudentList newList = list.filterByFaculty(faculty);
                try {
                    newList.writeRes("res.txt");
                } catch (const ifstream::failure& e) {
                    cout << e.what() << endl;
                    exit(1);
                }
                break;
            }
            case 4:
            {
                cout << "Input course" << endl;
                cin >> course;
                cout << endl;
                StudentList newList = list.filterByCourse(course);
                try {
                    newList.writeRes("res.txt");
                } catch (const ifstream::failure& e) {
                    cout << e.what() << endl;
                    exit(1);
                }
                break;
            }
            default:
                exit(1);
                break;
        }
    }
}
