//
//  iStudentList.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/14/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include "Student.h"
#include "StudentList.h"
#include "iStudentList.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
#define MAX_LENGTH 50

StudentList iStudentList::readData(char* path) {
    vector<Student> students;
    if (path != nullptr) {
        ifstream stream(path);
        char firstName[MAX_LENGTH];
        char lastName[MAX_LENGTH];
        char patronymic[MAX_LENGTH];
        char address[MAX_LENGTH];
        char phone[MAX_LENGTH];
        char faculty[MAX_LENGTH];
        char empty[MAX_LENGTH];
        int day;
        int month;
        int year;
        int course;
        Person person;
        Date date;
        Student student;
        if (stream.is_open()) {
            while (!stream.eof()) {
                stream >> lastName >> firstName >> patronymic;
                stream >> day >> month >> year;
                stream.getline(empty, sizeof empty);
                stream.getline(address, sizeof address);
                stream.getline(phone, sizeof phone);
                stream >> faculty >> course;
                if (stream.eof()) break;
                date = Date(year, month, day);
                person = Person(firstName, patronymic, lastName, phone, address, date);
                student = Student(person, faculty, course);
                students.push_back(student);
            }
            stream.close();
        } else {
            cout << "file can't be opened" << endl;
            exit(1);
        }
    }
    return StudentList(students);
}
