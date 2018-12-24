//
//   StudentList.h
//  lab-1
//
//  Created by Viktor Anashkin on 9/4/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef _StudentList_h
#define _StudentList_h
#include "Student.h"
#include <vector>
#include <string>

using namespace std;

class StudentList {
    vector<Student> students;

    void printElement(int);
public:
    void printAll();
    void writeRes(string);
    
    StudentList filterByFaculty(char*);
    StudentList filterByYear(int);
    StudentList filterByCourse(int);

    StudentList(vector<Student>);
    StudentList() {
        students = vector<Student>(0);
    }
};




#endif /* _StudentList_h */
