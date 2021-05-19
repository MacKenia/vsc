#include "numday.h"
#include "timeoff.h"
#include <iostream>
using namespace std;

timeoff::timeoff()
{
    cout << "请输入名称：";
    cin >> name;
    cout << "请输入编号：";
    cin >> number;
    cout << "请输入因生病可以不工作的最多天数：";
    maxSickDays = new numdays;
    cout << "请输入已经不工作的天数：";
    sickTaken = new numdays;
    cout << "请输入雇员可以带薪休假的天数：";
    maxVacation = new numdays;
    while (maxVacation->hou() > 24)
    {
        cout << "休假时间超过24H,重新输入：";
        cin >> *maxVacation;
    }
    cout << "请输入已经带薪休假的天数：";
    vacTaken = new numdays;
    cout << "请输入不支付薪水的情况下可以休假的天数：";
    maxUnpaid = new numdays;
    cout << "请输入不支付薪水的情况下已休假的天数：";
    unpaidTaken = new numdays;
}

timeoff::~timeoff()
{
    delete unpaidTaken;
    delete maxUnpaid;
    delete vacTaken;
    delete maxVacation;
    delete sickTaken;
    delete maxSickDays;
}

int timeoff::maxSick()
{
    return maxSickDays->hou();
}

void timeoff::showAll()
{
    cout << "因生病请假可不工作最大的天数：" << *maxVacation;
    cout << "因生病不工作的天数：" << *sickTaken;
    cout << "可带薪休假的最大天数：" << *maxVacation;
    cout << "已休假的天数：" << *vacTaken;
    cout << "不支付薪水的情况下的最大休假天数：" << *maxUnpaid;
    cout << "不支付薪水的情况下已休假的天数：" << *unpaidTaken;
}

bool timeoff::operator==(const char *a)
{
    for(int i = 0,j = 0; name[i] != '\0'||a[j] != '\0'; i++,j++)
    {
        if(name[i] != a[j]) return false;
    }
    return true;
}

bool timeoff::operator==(const int a)
{
    return number == a;
}
