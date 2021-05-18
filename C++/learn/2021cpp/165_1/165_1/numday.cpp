#include "numday.h"
#include <iostream>
using namespace std;

void numday::converse()
{
    if(day > 0 && hour < 0)
    {
        day--;
        hour+=8;
    }
    day += hour/8;
    hour = 0;
}

numday::numday()
{
    day = 0;
    hour = 0;
    cout << "请输入工作小时：";
    cin >> hour;
    converse();
}

numday& numday::operator+(numday &a)
{
    day += a.day;
    hour += a.hour;
    converse();
    return *this;
}

numday& numday::operator-(numday &a)
{
    day -= a.day;
    return *this;
}

numday& numday::operator+(int a)
{
    hour += a;
    converse();
    return *this;
}

numday& numday::operator-(int a)
{
    hour -= a;
    converse();
    return *this;
}

float numday::operator++()
{
    hour += 1;
    converse();
    return hour;
}

float numday::operator--()
{
    hour -= 1;
    converse();
    return hour;
}

float numday::operator--(int)
{
    float t = hour;
    hour -= 1;
    converse();
    return t;
}

float numday::operator++(int)
{
    float t = hour;
    hour += 1;
    converse();
    return t;
}

ostream& operator<<(ostream &strm, numday &a)
{
    cout << a.day << "天 " << a.hour << "小时" << endl;
    return strm;
}

istream& operator>>(istream &strm, numday &a)
{
    float t;
    cout << "输入天数：";
    cin >> t;
    a.day += t;
    return strm;
}

