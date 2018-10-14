//
//  Student.h
//  lab-1
//
//  Created by Viktor Anashkin on 9/2/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Student_h
#define Student_h
#include "Person.h"

#define MAX_LENGTH 50

class Student {
    Person personInfo;
    char faculty[MAX_LENGTH];
    int course;
    char res[200];
public:
    void setPersonInfo(Person);
    void setFaculty(char*);
    void setCourse(int);
    
    Person getPersonInfo();
    char* getFaculty();
    int getCourse();
    
    void print();
    char* toString();
    
    Student();
    Student(Person, char*, int);
    ~Student() {};
};


#endif /* Student_h */
