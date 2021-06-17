#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>

#include <unistd.h>

using namespace std;
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}

int sk()
{
    // FreeConsole();

    char t[255];
    // AllocConsole();
    GetConsoleTitleA(t,255);
    printf("%s\n",t);
    SetConsoleTitleA("kkkkk");
    getchar();
    printf("This is a subwindow.\n");
    for (int i = 0; i < 256; i++) 
    {
        color(i);  
        printf("%d\n",i);
    }
    cin.ignore();
    getchar();
    // FreeConsole();
    // AttachConsole(-1);
    printf("so\n");
    return 0;
}

int main()
{

    // Sleep(3000);
    getchar();
    for(int i = 0; i < 16; i++)
    {
        char t[] = "color 00";
        t[6] = '0' + i;
        system(t);
        getchar();
    }
    // FreeConsole();
    // AllocConsole();
    // sk();
    //FreeConsole();
    //AllocConsole();
    printf("ok");
    getchar();
    return 0;
}