#include <iostream>
#include <windows.h>
int main() 
{
     using namespace std; 
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
     SMALL_RECT rc; 
     rc.Left = 0; 
     rc.Top = 0; 
     rc.Right = 54; 
     rc.Bottom = 24; //此时窗口的宽度为50，高度为20 
     SetConsoleWindowInfo(hOut, TRUE, &rc); 
     for (int i = 0; i < 10; ++i) 
     cout << "**********" << i << endl; 
     cout << "0123456789" << endl; 
     cin.get(); 
     CloseHandle(hOut); 
     return 0; 
}