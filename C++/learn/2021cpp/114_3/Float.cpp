//
//  Float.cpp
//  114_3.cpp
//
//  Created by MacKenia on 2021/4/7.
//

#include <iostream>
#include <iomanip>
#include "Float.h"
using namespace std;

Float::Float(int count)
{
    p = new float[count];
    Count = count;
}

Float::~Float()
{
    delete []p;
}

void Float::insert()
{
    cout << "请输入" << Count << "个浮点数：";
    for (float *i = p; i < p+Count; i++) {
        cin >> *i;
//        cout  << *i;
    }
}

void Float::check()
{
    float sum = 0;
    for (float *i = p; i < p + Count; i++) {
        sum += *i;
//        cout << sum << endl;
    }
    sum /= Count;
    cout << "这" << Count << "个数的平均值为：" << setprecision(3) << sum << endl;
}
