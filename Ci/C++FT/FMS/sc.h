#include <windows.h>
#include <cstring>
#include <iostream>
#ifndef sc_h
#define sc_h

class sc //ScreenControl 窗口控制
{
private:
    static HANDLE had;   
    COORD cr;
    static CONSOLE_SCREEN_BUFFER_INFO csbi;
public:
    sc(const char*); //构造函数
    void setT(const char*); //设置窗口标题
    void color(int a); //修改文字输出的颜色
    void ccp(int, int); //ConsoleCursorPosition 控制台指针位置
    void setW(int, int); //设置窗口大小
    void setbc(const char *); //SetBackGroundColor 设置窗口背景颜色
    void cls(); //清空控制台
    friend char *intTochar(char*, int); //将整转换为字符型
};

#endif
