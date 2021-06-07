//
//  Payroll.cpp
//  114_4
//
//  Created by MacKenia on 2021/4/22.
//

#include "Payroll.h"
#include <iostream>
using namespace std;

float payroll::hSalary = 0;
bool payroll::flag = true;

void payroll::setM()
{
    cout << "请输入时薪：";
    cin >> hSalary;
}

payroll::payroll()
{
    if(!flag)
    {
        cout << "请输入时薪：";
        cin >> salary;
    }
    cout << "请输入已有工作小时：";
    cin >> wTime;
    while (wTime > 60 || wTime < 0) {
        cout << "输入时间大于60或小于0，请重新输入：";
        cin >> wTime;
    }
    if(!flag) wWage = salary * wTime;
    else wWage = wTime * hSalary;
}

float payroll::pay()
{
    return wWage;
}
