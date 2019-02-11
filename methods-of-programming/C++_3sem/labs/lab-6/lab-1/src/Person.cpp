//
//  Person.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/6/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include "Person.h"

void Person::setFirstName(char* name) {
    if (name != nullptr)  {
        strcpy(this->firstName, name);
    } else {
        strcpy(this->firstName, "");
    }
}

void Person::setLastName(char* name) {
    if (name != nullptr)  {
        strcpy(this->lastName, name);
    } else {
        strcpy(this->lastName, "");
    }
}

void Person::setPatronymic(char* name) {
    if (name != nullptr)  {
        strcpy(this->patronymic, name);
    } else {
        strcpy(this->patronymic, "");
    }
}

void Person::setPhone(char* phone) {
    if (phone != nullptr)  {
        strcpy(this->phone, phone);
    } else {
        strcpy(this->phone, "");
    }
}

void Person::setAddress(char* address) {
    if (address != nullptr)  {
        strcpy(this->address, address);
    } else {
        strcpy(this->address, "");
    }
}

void Person::setBirthdate(Date date) {
    birthdate = date;
}

char* Person::getFirstName() {
    return firstName;
}

char* Person::getLastName() {
    return lastName;
}

char* Person::getPatronymic() {
    return patronymic;
}

char* Person::getPhone() {
    return phone;
}

char* Person::getAddress() {
    return address;
}

Date Person::getBirthdate() {
    return birthdate;
}

Person::Person() {
    setFirstName("");
    setPatronymic("");
    setLastName("");
    setPhone("");
    setAddress("");
    setBirthdate(Date());
}

Person::Person(
               char* firstName,
               char* patronymic,
               char* lastName,
               char* phone,
               char* address,
               Date birthdate
               ) {
    setFirstName(firstName);
    setPatronymic(patronymic);
    setLastName(lastName);
    setPhone(phone);
    setAddress(address);
    setBirthdate(birthdate);
}
