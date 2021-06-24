#include "sc.h"
#ifndef control_h
#define control_h

class keyboard
{
private:
    int ch; //输入字符
    COORD coord; //屏幕上的坐标
    CONSOLE_SCREEN_BUFFER_INFO csbi; //控制台屏幕缓冲区信息
public:
    keyboard(); //构造函数
    
};

#endif