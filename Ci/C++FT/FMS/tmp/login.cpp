#include "login.h"
using namespace std;

login::login(const char *filename)
{
    pasFile.open(filename, ios::binary | ios::in);
    if(pasFile.fail())
    {
        cout << "初始化失败，请重试！" << endl;
        getchar();
        exit(0);
    }
    {
        // 登陆界面
        lo.setW(110,32);
        lo.setbc("e0");
        lo.ccp(22,4);
        lo.bw(22,65,20);
        cout << lo.color(112) << lo.ccp(48,4) << lo.title("登录");
        cout << lo.ccp(44,6) << "请登录"
        << lo.ccp(40,8);
        
    }
}

char* login::log()
{

    return username;
}

