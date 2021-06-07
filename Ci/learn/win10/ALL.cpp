#include<windows.h>
#include<stdio.h>

int sk()
{
    char t[255];
    AllocConsole();
    GetConsoleTitleA(t,255);
    printf("%s\n",t);
    SetConsoleTitleA("kkkkk");
    printf("This is a subwindow.\n");
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