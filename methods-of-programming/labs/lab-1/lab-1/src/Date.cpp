//
//  Date.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/6/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include "Date.h"
#include <cstring>
#include <string>
#include "DateValidator.h"

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

void Date::setYear(int year) {
    if (DateValidator::isValidYear(year)) {
        this->year = year;
    } else {
        this->year = -3;
    }
}


void Date::setMonth(int month) {
    if (DateValidator::isValidMonth(month)) {
        this->month = month;
    } else {
        this->month = -2;
    }
}

void Date::setDay(int day) {
    if (DateValidator::isValidDay(day)) {
        this->day = day;
    } else {
        this->day = -1;
    }
}

void Date::setDate(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

char* Date::toString() {
    std::string dayString = std::to_string(this->day);
    char* day = new char[dayString.length() - 1];
    strcpy(day, dayString.c_str());
    
    std::string monthString = std::to_string(this->month);
    char* month = new char[monthString.length() - 1];
    strcpy(month, monthString.c_str());
    
    std::string yearString = std::to_string(this->year);
    char* year = new char[yearString.length() - 1];
    strcpy(year, yearString.c_str());
    
    
    return strcat(strcat(strcat(strcat(day, "."), month), "."), year);
}

Date::Date() {
    setDate(2000, 4, 14);
}

Date::Date(int year, int month, int day) {
    setDate(year, month, day);
}
