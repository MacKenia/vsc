#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    int f;
    while (true)
    {
        if(GetKeyState(VK_ESCAPE) == -127) break; //按下esc退出
        f = GetKeyState(VK_CAPITAL); //显示状态
        cout << "\r    " << f << "   ";
        if(f)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	        Sleep(10);//要留给某些应用的反应时间
	        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }
        Sleep(600);
    }
    return 0;
}
