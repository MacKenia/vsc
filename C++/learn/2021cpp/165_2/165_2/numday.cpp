#include "numday.h"
#include <iostream>
using namespace std;

void numdays::converse()
{
    if(day > 0 && hour < 0)
    {
        day--;
        hour+=8;
    }
    day += hour/8;
    hour = 0;
}

numdays::numdays()
{
    day = 0;
    hour = 0;
    cout << "请输入工作小时：";
    cin >> hour;
    converse();
}

numdays& numdays::operator+(numdays &a)
{
    day += a.day;
    hour += a.hour;
    converse();
    return *this;
}

numdays& numdays::operator-(numdays &a)
{
    day -= a.day;
    return *this;
}

numdays& numdays::operator+(int a)
{
    hour += a;
    converse();
    return *this;
}

numdays& numdays::operator-(int a)
{
    hour -= a;
    converse();
    return *this;
}

float numdays::operator++()
{
    hour += 1;
    converse();
    return hour;
}

float numdays::operator--()
{
    hour -= 1;
    converse();
    return hour;
}

float numdays::operator--(int)
{
    float t = hour;
    hour -= 1;
    converse();
    return t;
}

float numdays::operator++(int)
{
    float t = hour;
    hour += 1;
    converse();
    return t;
}

ostream& operator<<(ostream &strm, numdays &a)
{
    cout << a.day << "天 " << a.hour << "小时" << endl;
    return strm;
}

istream& operator>>(istream &strm, numdays &a)
{
    float t;
    cout << "输入天数：";
    cin >> t;
    a.day += t;
    return strm;
}

