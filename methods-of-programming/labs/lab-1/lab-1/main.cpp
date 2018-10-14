//
//  main.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/2/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "StudentList.h"
#include "iStudentList.h"

using namespace std;

void showMenu(StudentList);

int main(int argc, const char * argv[]) {
    StudentList list = iStudentList::readData("data.txt");
    showMenu(list);
    return 0;
}

void showMenu(StudentList list) {
    int choice;
    char faculty[30];
    while(1) {
        cout << endl;
        cout << "1 - print all" << endl;
        cout << "2 - print by year" << endl;
        cout << "3 - print by faculty" << endl;
        cout << "4 - print by course" << endl;
        cout << "else exit" << endl;
        cout << endl;
        cin >> choice;
        int course;
        int year;
        switch (choice) {
            case 1:
            {
                list.printAll();
                break;
            }
            case 2:
            {
                cout << "Input year" << endl;
                cin >> year;
                cout << endl;
                StudentList newList = list.filterByYear(year);
                newList.printAll();
                break;
            }
            case 3:
            {
                cout << "Input faculty" << endl;
                cin >> faculty;
                cout << endl;
                StudentList newList = list.filterByFaculty(faculty);
                newList.printAll();
                break;
            }
            case 4:
            {
                cout << "Input course" << endl;
                cin >> course;
                cout << endl;
                StudentList newList = list.filterByCourse(course);
                newList.printAll();
                break;
            }
            default:
                exit(1);
                break;
        }
    }
}
