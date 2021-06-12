#include <windows.h>
#ifndef sc_h
#define sc_h

class sc //ScreenControl 窗口控制
{
    private:
        HANDLE had;
        COORD cr;
        POINT pt;
    public:
        sc();
        void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);} //修改文字输出的颜色
};

#endif
