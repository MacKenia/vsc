#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main()
{
    while(true)
    {
        if(GetKeyState(VK_ESCAPE) == -127) exit(0);
        Sleep(100);
        FreeConsole();
        cout << AllocConsole();
    }
    return 0;
}
