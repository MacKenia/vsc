#include <windows.h>
#include <conio.h>
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
    static HANDLE had; //窗口句柄
    COORD cr; //坐标
    static CONSOLE_SCREEN_BUFFER_INFO csbi; //控制台缓冲区信息
    struct frame fr; //界面框架
    int ch; //键盘按键
public:
    COORD top; //界面坐上坐标
    sc(); //无标题窗口的构造函数
    sc(const char*); //构造函数
    void flush(); //刷新屏幕缓冲区
    void setT(const char*); //设置窗口标题
    char color(int a); //修改文字输出的颜色
    char ccp(int, int); //ConsoleCursorPosition 控制台指针位置
    void ccp(COORD); //ConsoleCursorPosition 控制台指针位置
    void setW(int, int); //设置窗口大小
    void setbc(const char *); //SetBackGroundColor 设置窗口背景颜色
    void cls(); //清空控制台
    void bw(int=55, int=11); //输出一个空的方框
    char title(const char *); //设置界面标题
    friend char *intTochar(char*, int); //整转换为字符型
    char endline(); //换行
    void settop(int,int); //设置界面的左上角的坐标
    char text(int, int, const char *); //作为选项的文本
    char input(int, int, int=20); //输入框
    char texta(int, int, const char *); //选项激活的文本的文本
    char textb(int, int, const char *); //作为按钮的文本
    char textc(int, int, const char *); //激活的按钮
    void get(){ch = getch();} //获取按钮
    int button(); //返回键盘的按键 0回车 1↑ 2↓ 3← 4→
};

#endif
