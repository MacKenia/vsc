#include <iostream>
#include "sc.h"
using namespace std;

bool login()
{
    system("mode con cols=56 lines=13");
    sc lo("登录");
    Sleep(100);
    cout << "┌──────────────────────┤ LOGIN IN ├───────────────────┐" << endl;
    cout << "│                                                     │" << endl;
    cout << "│ You can type startvnc to start vncserver,type       │" << endl;
    cout << "│ stopvnc to stop it.                                 │" << endl;
    cout << "│ 您可以使用以下任意一条命令来启动vnc或x:             │" << endl;
    cout << "│ startvnc,tightvnc,tigervnc,startx11vnc,startxsdl,no │" << endl;
    cout << "│ vnc,输入stopvnc停止                                 │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│                       <确定>                        │" << endl;
    cout << "│                                                     │" << endl;
    cout << "└─────────────────────────────────────────────────────┘" << endl;
    getchar();
    lo.ccp(10,10);
    lo.color(6);
    cout << "josasldfjlkasdf";
    getchar();
    system("pause");
    return true;
}

int main()
{
    system("cls");
    sc mw("好友管理系统");
    mw.color(13);
    mw.ccp(10,10);
    cout << "请在弹出窗口中登录";
    mw.newD();
    login();
}