#include<windows.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}

int sk()
{
    char t[255];
    AllocConsole();
    GetConsoleTitleA(t,255);
    printf("%s\n",t);
    SetConsoleTitleA("kkkkk");
    printf("This is a subwindow.\n");
    for (int i = 0; i < 256; i++) 
    {
        color(i);
        cout << i << " " << endl;
    }
    getchar();
    FreeConsole();
    AttachConsole(-1);
    return 0;
}

int main()
{
    Sleep(3000);
    FreeConsole();
    sk();
    //FreeConsole();
    //AllocConsole();
    printf("ok");
    getchar();
    return 0;
}