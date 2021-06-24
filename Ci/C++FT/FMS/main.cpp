#include <iostream>
#include "frd.h"
#include "login.h"
using namespace std;

void GetPos(POINT &pt){//获得鼠标相对于屏幕的位置
//POINT是自带类型
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16,pt.x=pt.x/8;//除以16，想不明白自己把它去掉试试
}

int main()
{
    POINT pt;
    login log;
    cout << log.log();
    while(true)
    {
        GetPos(pt);
        cout << "(" << pt.x << "," << pt.y << ")"<<"\r";
    }
    getchar();
    
}