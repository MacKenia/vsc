//
//  student.cpp
//  examine
//
//  Created by MacKenia on 2021/5/5.
//

#include "student.h"
#include <iostream>

using namespace std;

float student::avg1=0, student::avg2=0, student::avg3=0;
int student::total = 0;
int rank[5]={0};


student::student()
{
    cout << "请输入理论成绩：";
    cin >> theory;
    while (theory<0||theory>100)
    {
        cout << "输入有误，请输入理论成绩：";
        cin >> theory;
    }
    cout << "请输入操作成绩：";
    cin >> operate;
    while (operate<0||operate>100)
    {
        cout << "输入有误，请输入操作成绩：";
        cin >> operate;
    }
    cout << "请输入问答成绩：";
    cin >> qa;
    while (qa<0||qa>100)
    {
        cout << "输入有误，请输入问答成绩：";
        cin >> qa;
    }
    cin.ignore();
    total++;
    avg1 = (avg1+theory)/total;
    avg2 = (avg2+operate)/total;
    avg3 = (avg3+qa)/total;
    num = total;
    for(int i = 0; i < 5; i++)
    {
        if(rank[0][i] < (theory+operate+qa))
        {
            for(int j = 5; j > i;j--)
            {
                int t = rank[0][j-1];
                rank[0][j] = t;
            }
        }
    }
}

void printrank()
{
    cout << "" << endl;
}

