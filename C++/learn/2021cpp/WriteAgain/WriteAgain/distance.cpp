//
//  distance.cpp
//  WriteAgain
//
//  Created by MacKenia on 2021/4/23.
//
#include <iostream>
#include <cmath>
#include "distance.h"
using namespace std;

Point::Point(int a,int b)
{
    xPos = a;
    yPos = b;
}

double distance(Point &a, Point &b)
{
    double x = a.xPos - b.xPos;
    double y = a.yPos - b.yPos;
    return sqrt(x*x+y*y);
}

