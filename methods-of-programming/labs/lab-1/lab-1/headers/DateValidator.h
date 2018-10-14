//
//  DateValidator].h
//  lab-1
//
//  Created by Viktor Anashkin on 9/15/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef DateValidator__h
#define DateValidator__h
#include "Date.h"

class DateValidator {
public:
    static bool isValidDay(int);
    static bool isValidYear(int);
    static bool isValidMonth(int);
};

#endif /* DateValidator__h */
