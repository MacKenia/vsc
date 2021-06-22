#include "login.h"
using namespace std;

login::login()
{
    if(pasFile.fail())
    {
        cout << "初始化，请重试！" << endl;
        getchar();
        exit(0);
    }
    {
        // 登陆界面
        sc::bw();
        
    }
}

char login::log()
{

    return username;
}

