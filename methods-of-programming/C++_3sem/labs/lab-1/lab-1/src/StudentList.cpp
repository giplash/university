//
//  StudentList.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/6/18.
//  Copyright © 2018 BSU. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include "StudentList.h"


void StudentList::printElement(int i) {
    cout << students[i].toString() << endl;
    cout << "-------------------------" << endl;
}


StudentList StudentList::filterByFaculty(char* faculty) {
    vector<Student> newStudents;
    if (faculty != nullptr) {
        for (int i = 0; i < students.size(); i++) {
            if (strcmp(students[i].getFaculty(), faculty) == 0) {
                newStudents.push_back(students[i]);
            }
        }
    }
    return StudentList(newStudents);
}

StudentList StudentList::filterByCourse(int course) {
    vector<Student> newStudents;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getCourse() == course) {
            newStudents.push_back(students[i]);
        }
    }
    return StudentList(newStudents);
};

StudentList StudentList::filterByYear(int year) {
    vector<Student> newStudents;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getPersonInfo().getBirthdate().getYear() >= year) {
            newStudents.push_back(students[i]);        }
    }
    return StudentList(newStudents);
}

void StudentList::printAll() {
    for (int i = 0; i < students.size(); i++) {
        printElement(i);
    }
}


StudentList::StudentList(vector<Student> students) {
    this->students = students;
}
