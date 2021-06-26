#include <iostream>
#include "frd.h"
using namespace std;

int main()
{
    sc mw("操作界面搭建");
    mw.setW(110,32);
    
    frd user("mackenia");
    user.addf();
    // for(int i = 0; i < 5; i++) user.addf();
    // user.shwf();
    // user.rmvf(user.secf("test"));
    user.modf();
    getchar();
    
}