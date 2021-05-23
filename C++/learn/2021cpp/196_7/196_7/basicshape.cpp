//
//  basicshape.cpp
//  196_7
//
//  Created by MacKenia on 2021/5/21.
//

#include <iostream>
#include "basicshape.h"
using namespace std;

// circle

circle::circle()
{
    cout << "请输入X坐标：";
    cin >> centerx;
    cout << "请输入Y坐标：";
    cin >> centery;
    cout << "请输入半径：";
    cin >> radius;
    calcarea();
}

// rectangle

rectangle::rectangle()
{
    cout << "请输入宽度：";
    cin >> width;
    cout << "请输入长度：";
    cin >> length;
    calcarea();
}
