#include <iostream>
#include "frd.h"
using namespace std;

int main()
{
    sc mw("操作界面搭建");
    mw.setW(110,32);
    
    frd user("mackenia");
    user.rmvf();
    user.showall();
    getchar();
    
}