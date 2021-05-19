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
    
}

int timeoff::s()
{
    return maxSickDays->hou();
}
