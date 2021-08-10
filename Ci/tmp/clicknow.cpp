#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    int f, loop = 7;
    while (++loop)
    {
        if(GetKeyState(VK_ESCAPE) == -127) break; //按下esc退出
        f = GetKeyState(VK_CAPITAL); //显示状态
        cout << "\r    " << f << "   ";
        if(f && !(loop%100))
        {
            cout << "\n" << loop;
            // mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	        Sleep(10);//要留给某些应用的反应时间
	        // mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            keybd_event(VK_SPACE,0,0,0);
            keybd_event(VK_SPACE,KEYEVENTF_KEYUP,0,0);
        }
        Sleep(10);
        if(loop == INT_MAX) loop = 7;
    }
    return 0;
}
