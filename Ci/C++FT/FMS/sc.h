#include <windows.h>
#include <cstring>
#include <iostream>
#ifndef sc_h
#define sc_h

struct frame // 方框框架
{
    char lt[4] = "┌";
    char rt[4] = "┐";
    char lm[4] = "┤";
    char rm[4] = "├";
    char lb[4] = "└";
    char rb[4] = "┘";
    char row[4] = "─";
    char col[4] = "│";
};

class sc //ScreenControl 窗口控制
{
private:
    static HANDLE had;   
    COORD cr, top;
    static CONSOLE_SCREEN_BUFFER_INFO csbi;
    char tit[25];
    struct frame fr;
public:
    sc(); //无标题窗口的构造函数
    sc(const char*); //构造函数
    void flush(); //刷新屏幕缓冲区
    void setT(const char*); //设置窗口标题
    char color(int a); //修改文字输出的颜色
    char ccp(int, int); //ConsoleCursorPosition 控制台指针位置
    void setW(int, int); //设置窗口大小
    void setbc(const char *); //SetBackGroundColor 设置窗口背景颜色
    void cls(); //清空控制台
    void bw(int=0,int=55, int=11); //输出一个空的方框
    char title(const char *); //设置标题
    friend char *intTochar(char*, int); //整转换为字符型
    char endline(int); //换行
    void settop(int,int);
};

#endif
