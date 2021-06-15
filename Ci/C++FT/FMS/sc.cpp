# include "sc.h"

sc::sc(const char *s)
{
    had = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(had, &csbi);
    SetConsoleTitleA(s);
    cr.X = csbi.dwCursorPosition.X;
    cr.Y = csbi.dwCursorPosition.Y;
}

void sc::color(int a)
{
    SetConsoleTextAttribute(had, a);
}

void sc::newD()
{
    FreeConsole();
    AllocConsole();
}

void sc::ccp(int x, int y)
{
    cr.X = x;
    cr.Y = y;
    SetConsoleCursorPosition(had,cr);
}

void sc::setW(int w, int h)
{
    char s[] = "mode con cols=40 lines=12";
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '=')
        {
            // s[i+1]
        }
    }
}
