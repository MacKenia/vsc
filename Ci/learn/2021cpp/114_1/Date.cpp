#include"Date.h"
#include<iostream>
#include<cstring>
using namespace std;

void Date::e(int i, char *tmp)
{
    char Month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "Septembei", "October", "November", "December"};
    switch (i)
    {
        case 1: strcpy(tmp, Month[0]);
                break;
        case 2: strcpy(tmp, Month[1]);
                break;
        case 3: strcpy(tmp, Month[2]);
                break;
        case 4: strcpy(tmp, Month[3]);
                break;
        case 5: strcpy(tmp, Month[4]);
                break;
        case 6: strcpy(tmp, Month[5]);
                break;
        case 7: strcpy(tmp, Month[6]);
                break;
        case 8: strcpy(tmp, Month[7]);
                break;
        case 9: strcpy(tmp, Month[8]);
                break;
        case 10: strcpy(tmp, Month[9]);
                break;
        case 11: strcpy(tmp, Month[10]);
                break;
        case 12: strcpy(tmp, Month[11]);
                break;
    }
}

void Date::set()
{
    cout << "请输入年月日(以空格分割):";
    cin >> iyear;
    cin >> imonth;
    if(imonth>=12||imonth<=1) imonth = 0;
    cin >> iday;
    if(iday>=31||iday<=1) iday = 0;
}

void Date::set(int a, int b, int c)
{
    if(b>=12||b<=1||c>=31||c<=1) return;
    iday = c;
    imonth = b;
    iyear = a;
}

void Date::shownum()
{
    cout << iday << "-" << imonth << "-" << iyear << endl;
}

void Date::showmon()
{
    char tmp[20];
    e(imonth,tmp);
    cout << tmp << " " << iday << "," << iyear <<  endl;
}

void Date::showday()
{
    char tmp[20];
    e(imonth,tmp);
    cout << iday << " " << tmp << " " << iyear <<  endl;
}

