#include "numday.h"
#include <iostream>
using namespace std;

void numdays::converse(const bool &f)
{
    if(f) day = hour/8;
    else hour = day * 8;
}

numdays::numdays()
{
    day = 0;
    hour = 0;
    cin >> day;
    converse(false);
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
    converse(true);
    return *this;
}

numdays& numdays::operator-(int a)
{
    hour -= a;
    converse(true);
    return *this;
}

float numdays::operator++()
{
    hour += 1;
    converse(true);
    return hour;
}

float numdays::operator--()
{
    hour -= 1;
    converse(true);
    return hour;
}

float numdays::operator--(int)
{
    float t = hour;
    hour -= 1;
    converse(true);
    return t;
}

float numdays::operator++(int)
{
    float t = hour;
    hour += 1;
    converse(true);
    return t;
}

ostream& operator<<(ostream &strm, numdays &a)
{
    cout << a.day << "天" << endl;
    return strm;
}

istream& operator>>(istream &strm, numdays &a)
{
    cout << "目前工作小时数为：" << a.hour << "，输入工作小时数：";
    cin >> a.hour;
    a.converse(true);
    return strm;
}

