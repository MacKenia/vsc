//
//  time.cpp
//  208_2
//
//  Created by MacKenia on 2021/5/26.
//

#include "time.h"
using namespace std;

mlitime::mlitime(int a, int b):time(a/100,a%100,b)
{
    if(a > 2359|| a < 0) throw overflowhour();
    if(b >59 || b < 0) throw overflowsec();
}

