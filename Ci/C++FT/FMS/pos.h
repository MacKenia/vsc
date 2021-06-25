#include <iostream>
#include <windows.h>
#include <conio.h>
#ifndef pos_h
#define pos_h

class pos
{
private:
    HWND hwnd=GetForegroundWindow();
    POINT pt;
public:
    pos(); //构造函数
};

#endif