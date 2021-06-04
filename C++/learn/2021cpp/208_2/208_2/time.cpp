//
//  time.cpp
//  208_2
//
//  Created by MacKenia on 2021/5/26.
//

#include "time.h"
using namespace std;

mlitime::mlitime(int a, int c):time(a/100,a%100,c)
{
    if(a > 2359) throw overflowhour();
    if(c >59) throw overflowsec();
}

