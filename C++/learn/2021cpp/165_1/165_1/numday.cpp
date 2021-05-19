#include "numday.h"
#include <iostream>
using namespace std;

void numdays::converse(const bool &f)
{
    if(f) day = hour/8;
    else hour = day*8;
}

numdays::numdays()
{
    day = 0;
    hour = 0;
    cout << "请输入工作小时：";
    cin >> hour;
    converse(true);
}

float numdays::da()
{
    return day;
}

int numdays::hou()
{
    return hour;
}

numdays& numdays::operator+(numdays &a)
{
    day += a.day;
    hour += a.hour;
    return *this;
}

numdays& numdays::operator-(numdays &a)
{
    day -= a.day;
    hour -= a.hour;
    return *this;
}

bool numdays::operator==(const float a)
{
    return day == a;
}

numdays& numdays::operator+(int a)
{
    hour += a;
    converse(false);
    return *this;
}

numdays& numdays::operator-(int a)
{
    hour -= a;
    converse(false);
    return *this;
}

float numdays::operator++()
{
    hour += 1;
    converse(false);
    return hour;
}

float numdays::operator--()
{
    hour -= 1;
    converse(false);
    return hour;
}

float numdays::operator--(int)
{
    float t = hour;
    hour -= 1;
    converse(false);
    return t;
}

float numdays::operator++(int)
{
    float t = hour;
    hour += 1;
    converse(false);
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
    a.converse(true);
    return strm;
}

