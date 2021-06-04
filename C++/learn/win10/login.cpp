#include <iostream>
#include <windows.h>


using namespace std;

int login()
{
    AllocConsole();
    cout << "User Name:";
    cout << "Password:";
    AttachConsole(-1);
    return 0;
}

int main()
{
    cout << "请在弹出窗口中登录!" << endl;
    FreeConsole();    
    return 0;
}
