//
//  Student.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/6/18.
//  Copyright © 2018 BSU. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include "Student.h"
using namespace std;

void Student::setPersonInfo(Person info) {
    personInfo = info;
}

void Student::setFaculty(char* faculty) {
    if (faculty != nullptr) {
        strcpy(this->faculty, faculty);
    } else {
        strcpy(this->faculty, "");
    }
}

void Student::setCourse(int course) {
    this->course = course;
}

Person Student::getPersonInfo() {
    return personInfo;
}

char* Student::getFaculty() {
    return this->faculty;
}

int Student::getCourse() {
    return course;
}

void Student::print() {
    Person info = getPersonInfo();
    
    char* lastName = info.getLastName();
    char* firstName = info.getFirstName();
    char* patronymic = info.getPatronymic();
    char* fullName = strcat(strcat(strcat(strcat(lastName, " "), firstName), " "), patronymic);
    cout << fullName << endl;
    cout << info.getBirthdate().toString() << endl;
    cout << info.getAddress() << endl;
    cout << info.getPhone() << endl;
    cout << "faculty: " << faculty <<  ", course: " << course << endl;
}

char* Student::toString() {
    Person info = getPersonInfo();
    char* lastName = info.getLastName();
    char* firstName = info.getFirstName();
    char* patronymic = info.getPatronymic();
    strcpy(res, strcat(strcat(strcat(strcat(lastName, " "), firstName), " "), patronymic));
    strcat(res, "\n");
    strcat(res, info.getBirthdate().toString());
    strcat(res, "\n");
    strcat(res, info.getAddress());
    strcat(res, "\n");
    strcat(res, info.getPhone());
    strcat(res, "\nfaculty: ");
    strcat(res, faculty);
    strcat(res, ", course: ");
    std::string courseString = std::to_string(course);
    char* course = new char[courseString.length() - 1];
    strcpy(course, courseString.c_str());
    strcat(res, course);
    return res;
}

Student::Student() {
    personInfo = Person();
    strcpy(faculty, "mmf");
    course = 1;
}

Student::Student(Person info, char* faculty, int course) {
    setPersonInfo(info);
    setFaculty(faculty);
    setCourse(course);
}
