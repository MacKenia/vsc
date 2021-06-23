#include "login.h"
using namespace std;

login::login()
{
    pasFile.open(filename, ios::binary | ios::in | ios::out);
    if(pasFile.fail())
    {
        cout << "初始化，请重试！" << endl;
        getchar();
        exit(0);
    }
}

char* login::log()
{
    char Username[20];
    char Password[20];
    char data[40];
    if(pasFile.fail()) pasFile.open(filename, ios::binary | ios::in);
    if(pasFile.fail())
    {
        cout << "初始化，请重试！" << endl;
        getchar();
        exit(0);
    }
    {
        // 登陆界面
        lo.setW(120,60);
        lo.setbc("e0");
        lo.ccp(50,30);
        lo.bw(50);
    }
    while(!pasFile.eof())
    {
        if(pasFile.fail()) break;
        pasFile.read((char*)&data, sizeof(data));
        for(int i = 0; i < 40; i++)
        {
            if(i < 20)
            {
                cout << "用户名错误，请重试";
                if(data[i] != Username[i]) return log();
            }
            else
            {
                cout << "密码错误，请重试";
                if(data[i] != Password[i]) return log();
            }
        }
    }
    pasFile.close();
    return username;
}

void login::sign()
{ 
    pasFile.open(filename, ios::binary | ios::in | ios::out);
    if(pasFile.fail())
    {
        cout << "初始化，请重试！" << endl;
        getchar();
        exit(0);
    }
    char Username[20];
    char Password[20];
    //注册界面
    {

    }
    if(pasFile.fail()) 
    {
        
    }
    pasFile.seekg(0L, ios::end);
    pasFile.close();
}

