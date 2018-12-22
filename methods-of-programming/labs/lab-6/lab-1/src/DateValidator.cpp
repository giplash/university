//
//  DateValidator.cpp
//  lab-1
//
//  Created by Viktor Anashkin on 9/15/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "DateValidator.h"

bool DateValidator::isValidDay(int day) {
    return (day >= 1 && day <=31);
}

bool DateValidator::isValidMonth(int month) {
    return (month >=1 && month <= 12);
}

bool DateValidator::isValidYear(int year) {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int currentYear = aTime->tm_year + 1900;
    return ((year < currentYear - 14) && year > 1940);
}
