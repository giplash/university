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
#include <string>
#include <stdexcept>
#include "InvalidYear.h"
#include "StudentList.h"

using namespace std;

void StudentList::printElement(int i) {
    cout << students[i].toString() << endl;
    cout << "-------------------------" << endl;
}


StudentList StudentList::filterByFaculty(char* faculty) {
    if (strlen(faculty) < 2) {
        string message = "invalid faculty";
        throw message;
    }
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
    if (year >= 2002 || year < 1995) {
        throw InvalidYear();
    }
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

void StudentList::writeRes(string path) {
    ofstream out;
    out.open(path, ofstream::out | ofstream::trunc);
    if (!out.is_open()) {
        throw ofstream::failure("Exception opening/reading file");
    }
    string result = "";
    for (int i = 0; i < students.size(); i++) {
        result += students[i].toString();
        result += '\n';
        result += '\n';
    }
    out << result;
    out.close();
}

StudentList::StudentList(vector<Student> students) {
    this->students = students;
}

