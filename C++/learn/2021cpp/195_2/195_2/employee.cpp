//
//  employee.cpp
//  195_2
//
//  Created by MacKenia on 2021/5/14.
//

#include <iostream>
#include "employee.h"
using namespace std;

employee::employee()
{
    name = new char[8];
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入编号：";
    cin >> num.s;
}

employee::~employee()
{
    delete []name;
}

bool employee::findname(const char *p)
{
    return name == p;
}

bool employee::findnum(const char *p)
{
    return num == p;
}

