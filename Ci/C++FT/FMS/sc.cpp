# include "sc.h"

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

void sc::setT(const char *s)
{
    SetConsoleTitleA(s);
}

void sc::color(int a)
{
    SetConsoleTextAttribute(had, a);
}

void sc::ccp(int x, int y)
{
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    cr.X = x;
    cr.Y = y;
    SetConsoleCursorPosition(had,cr);
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

