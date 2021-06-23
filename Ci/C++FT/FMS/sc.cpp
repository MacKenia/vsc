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
    COORD crt;
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    crt.Y = csbi.dwCursorPosition.Y;
    crt.Y++;
    crt.X = top.X;
    SetConsoleCursorPosition(had,crt);
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
{
    char hd[9] = "color ";
    strcat(hd, b);
    system(hd);
}

char sc::title(const char *s)
{
    cout << fr.lm ;
    cout << ' ' << color(116) << s << color(114);
    cout << fr.rm;
    return 0;
}

void sc::bw(int x,int w, int h)
{
    
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
        cout << endline(x);
    }
    cout << color(224) << ' ';
    for(int i = 0; i <= w; i++) cout << color(7) << ' ';
}

