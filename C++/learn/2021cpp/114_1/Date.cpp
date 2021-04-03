#include"Date.h"
#include<iostream>
using namespace std;

void Date::set(int a, int b, int c, int d, char *s)
{
    iday = c;
    imonth = b;
    iyear = a;
    icentury = d;
    sx = s;
}
