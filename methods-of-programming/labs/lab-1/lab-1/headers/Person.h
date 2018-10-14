//
//  Person.h
//  lab-1
//
//  Created by Viktor Anashkin on 9/2/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Person_h
#define Person_h
#include "Date.h"
#define MAX_LENGTH 50

using namespace std;


class Person {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char patronymic[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char address[MAX_LENGTH];
    Date birthdate;
    
public:
    void setFirstName(char*);
    void setLastName(char*);
    void setPatronymic(char*);
    void setPhone(char*);
    void setAddress(char*);
    void setBirthdate(Date);
    
    char* getFirstName();
    char* getLastName();
    char* getPatronymic();
    char* getPhone();
    char* getAddress();
    Date getBirthdate();
    
    Person();
    Person(char*, char*, char*, char*, char*, Date);
    ~Person() {};
};

#endif /* Person_h */
