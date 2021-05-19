//
//  numday.h
//  165_2
//
//  Created by MacKenia on 2021/5/14.
//
#include "numday.h"
#ifndef numday_h
#define numday_h
class timeoff
{
private:
    char name[10];
    int number;
    numdays maxSickDays;
    numdays sickTaken;
    numdays maxVacation;
    numdays vacTaken;
    numdays maxUnpaid;
    numdays unpaidTaken;
    void check();
public:
    timeoff();
    
};

#endif /* numday_h */
