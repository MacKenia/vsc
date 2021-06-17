#include <iostream>
#include "sc.h"
using namespace std;


sc mw("好友管理系统");

bool login()
{
    char name;
    mw.setT("登录");
    mw.setW(56, 13);
    Sleep(100);
    mw.setbc("E0");
    cout << "┌─────────────────────┤ LOGIN IN ├────────────────────┐" << endl;
    cout << "│                                                     │" << endl;
    cout << "│                        请登录                       │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│         用户名：__________________________          │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│           密码：__________________________          │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│               <登录>             <注册>             │" << endl;
    cout << "│                                                     │" << endl;
    cout << "└─────────────────────────────────────────────────────┘" << endl;
    mw.ccp(18,4);
    cin >> name;
    getchar();
    system("pause");
    return true;
}

int main()
{
    login();
}