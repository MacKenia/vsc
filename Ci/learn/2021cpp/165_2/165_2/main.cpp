//
//  main.cpp
//  165_2
//
//  Created by MacKenia on 2021/5/14.
//

#include <iostream>
#include "timeoff.h"
using namespace std;

int main()
{
    // insert code here...
    int month;
    float a[6]={1,0,1.5,0,0,0};
    cout << "请输入以工作的月数：";
    cin >> month;
    cout << "请输入雇员生病的天数：";
    cin >> a[1];
    cout << "请输入带薪休假的天数：";
    cin >> a[3];
    cout << "请输入不支付薪水可以休假的最多天数：";
    cin >> a[4];
    cout << "请输入不支付薪水已经休假的天数：";
    cin >> a[5];
    timeoff one(a[0],a[1],a[2],a[3],a[4],a[5]);
    cout << endl;
    cout << "一共可以因病休假：" << month*one.check(1) << "天，"  << "一共可以正常休假：" << month*one.check(3) << "天" << endl;
    return 0;
}
