#include <iostream>
#include "frd.h"
using namespace std;

int main()
{
    sc mainw("操作界面搭建");
    mainw.setW(110,32);
    frd user("mackenia");
    user.addf();
    user.addf();
    user.showall();
    getchar();
    
}