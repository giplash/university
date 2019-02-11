//
//  Date.h
//  lab-1
//
//  Created by Viktor Anashkin on 9/2/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef Date_h
#define Date_h
#include <stdlib.h>
#include <stdio.h>


using namespace std;

class Date {
    int year;
    int month;
    int day;
    
public:
    void setDate(int, int, int);
    
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    
    int getYear();
    int getMonth();
    int getDay();
    
    char* toString();
    
    Date();
    Date(int, int, int);
    ~Date() {};
};


#endif /* Date_h */
