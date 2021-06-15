#include <windows.h>
#ifndef sc_h
#define sc_h

class sc //ScreenControl 窗口控制
{
private:
    HANDLE had;
    COORD cr;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
public:
    sc(const char*);
    void color(int a); //修改文字输出的颜色
    void newD(); //新窗口
    void backD(); //返回上一个窗口
    void ccp(int, int); //ConsoleCursorPosition 控制台指针位置
    void setW(int, int); //设置窗口大小
};

#endif
