//
//  Population.cpp
//  114_2
//
//  Created by MacKenia on 2021/4/22.
//

#include <iostream>
#include "Population.h"
using namespace std;

float Population::bornrate()
{
    return (float)bp/people;
}

float Population::deathrate()
{
    return (float)dp/people;
}

Population::Population()
{
    cout << "请输入当前的人数：";
    cin >> people;
    while(people <= 1)
    {
        cout << "输入人数小于等于1，请重新输入：";
        cin >> people;
    }
    cout << "请输入出生的人数：";
    cin >> bp;
    while (bp<0) {
        cout << "输入人数小于0，请重新输入：";
        cin >> bp;
    }
    cout << "请输入死亡的人数：";
    cin >> dp;
    while (dp < 0) {
        cout << "输入人数小于0，请重新输入：";
        cin >> dp;
    }
}
