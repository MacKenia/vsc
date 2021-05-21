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
    cout << "请输入受雇日期(YYMMDD)：";
    cin >> hire;
    
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

char *employee::gname()
{
    return name;
}

char *employee::gnum()
{
    return num.s;
}

int employee::ghire()
{
    return hire;
}

ostream& operator<<(ostream &strm, employee &a)
{
    strm << "姓名为：" << a.name << endl
    << "雇员编号为：" << a.num.s << endl
    << "雇佣日期为：" << a.hire << endl;
    return strm;
}


//  employeepay 类的函数扩充

employeepay::employeepay()
{
    cout << "请输入每个月的工资：";
    cin >> wage;
    while (wage <= 0) {
        cout << "输入数据有误，重新输入：";
        cin >> wage;
    }
    cout << "请输入部门号：";
    cin >> dept;
}

ostream& operator<<(ostream& strm, employeepay& a)
{
    strm << "姓名为：" << a.gname() << endl
    << "雇员编号为：" << a.gnum() << endl
    << "雇佣日期为：" << a.ghire() << endl
    << "月工资为：" << a.wage << endl
    << "部门编号为：" << a.dept << endl;
    return strm;
}

