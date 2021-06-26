# include "sc.h"

using namespace std;

char* intTochar(char *s,int a);

HANDLE sc::had = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO sc::csbi;

sc::sc(const char *s)
{
    GetConsoleScreenBufferInfo(had, &csbi);
    SetConsoleTitleA(s);
    cr.X = csbi.dwCursorPosition.X;
    cr.Y = csbi.dwCursorPosition.Y;
}

sc::sc()
{
    GetConsoleScreenBufferInfo(had, &csbi);
    cr.X = csbi.dwCursorPosition.X;
    cr.Y = csbi.dwCursorPosition.Y;
}

void sc::flush()
{
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    cr.X = csbi.dwCursorPosition.X;
    cr.Y = csbi.dwCursorPosition.Y;
}

void sc::settop(int x, int y)
{
    top.X = x;
    top.Y = y;
}

void sc::setT(const char *s)
{
    SetConsoleTitleA(s);
}

char sc::color(int a)
{
    SetConsoleTextAttribute(had, a);
    return 0;
}

char sc::ccp(int x, int y)
{
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    cr.X = x;
    cr.Y = y;
    SetConsoleCursorPosition(had,cr);
    return 0;
}

void sc::ccp(COORD a)
{
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    SetConsoleCursorPosition(had,a);
}

void sc::setW(int w, int h)
{
    char hd[26] = "mode con cols=";
    char wid[4];
    char d[] = " lines=";
    char hei[4];
    intTochar(wid, w);
    intTochar(hei, h);
    strcat(hd, wid), strcat(hd, d), strcat(hd, hei);
    system(hd);
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
}

char sc::endline()
{
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    cr.Y = csbi.dwCursorPosition.Y + 1;
    if(csbi.dwSize.Y - cr.Y < 6)
    {
        top.X += 20;
        cr.Y = top.Y;
    }
    cr.X = top.X;
    SetConsoleCursorPosition(had,cr);
    return 0;
}

char* intTochar(char *s,int a)
{
    int w = 3;
    if(a/100 == 0) w = 2;
    else if(a/10 == 0) w = 1;
    for(int i = 0; i < w; i++, a/=10)
    {
        s[w-1-i] = '0' + a % 10;
    }
    s[w] = '\0';
    return s;
}

void sc::cls()
{
    system("cls");
}

void sc::setbc(const char *b)
{//c7 红色 e0 黄色 af 绿色
    char hd[9] = "color ";
    strcat(hd, b);
    system(hd);
}

char sc::title(const char *s)
{
    ccp(top.X+3,top.Y);
    cout << color(112) << fr.lm ;
    cout << ' ' << color(124) << s << color(112);
    cout << fr.rm;
    return 0;
}


char sc::text(int x, int y, const char *s,int c)
{
    ccp(x, y);
    color(c);
    cout << s;
    for(int i = 0; i < 28-strlen(s); i++) cout << ' ';
    ccp(x, y);
    color(240);
    return 0;
}

char sc::texta(int x, int y, const char *s,int c)
{
    ccp(x, y);
    color(c);
    cout << s;
    for(int i = 0; i < 28-strlen(s); i++) cout << ' ';
    ccp(x, y);
    color(240);
    return 0;
}

char sc::textb(int x, int y, const char *s,int c)
{
    ccp(x, y);
    color(c);
    cout << s;
    ccp(x, y);
    color(240);
    return 0;
}
char sc::textc(int x, int y, const char *s,int c)
{
    ccp(x, y);
    color(c);
    cout << s;
    ccp(x, y);
    color(240);
    return 0;
}

char sc::input(int x, int y, int n)
{
    ccp(x, y);
    color(240);
    for(int i = 0; i < n; i++) cout << '_';
    return 0;
}

void sc::bw(int w, int h)
{
    cls();
    ccp(top);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            color(112);
            bool flag = true;
            // 第一行
            if(i == 0 && j == 0)
            {
                cout << fr.lt;
                flag = false;
            }
             else if(i == 0 && j > 0 && j < w-1)
            {
                cout << fr.row;
                flag = false;
            }
            else if(i == 0 && j == w-1)
            {
                cout << fr.rt << " ";
                flag = false;
            }
            // 最后一行
            if(i == h-1 && j == 0)
            {
                cout << fr.lb;
                flag = false;
            }
            else if(i == h-1 && j > 0 && j < w-1)
            {
                cout << fr.row;
                flag = false;
            }
            else if(i == h-1 && j == w-1)
            {
                cout << fr.rb << " ";
                if(j == w-1) cout  << color(7) << ' ';
                flag = false;
            }
            // 其他行
            if((i > 0 && i < h-1)&&(j == 0 || j == w-1))
            {
                cout << fr.col;
                if(i && j == w-1) cout << color(114) << " " << color(7) << " ";
                flag = false;
            }
            if(flag) cout << ' ';
        }
        // cout << endline();
        had = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(had, &csbi);
        ccp(top.X, csbi.dwCursorPosition.Y + 1);
    }
    ccp(top.X+1,top.Y+h);
    for(int i = 0; i <= w; i++) cout << color(7) << ' ';
}

int sc::button()
{
    //回车
    if(ch==0x0d)
    {
        return 0;
    }
    //上
    else if(ch==0x48)
    {
        return 1;
    }
 
    //下
    else if(ch==0x50)
    {
        return 2;
    }
 
    //左
    else if(ch==0x4b)
    {
        return 3;
    }
 
    //右
    else if(ch==0x4d)
    {
        return 4;
    }
    else return 5;
}

