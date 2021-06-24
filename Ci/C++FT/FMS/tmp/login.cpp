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
    pasFile.close();
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
        lo.setW(110,32);
        lo.setbc("e0");
        lo.settop(22,4);
        lo.bw(65,20);
        cout << lo.title("登录");
        cout << lo.ccp(44,6) << "请登录"
        << lo.ccp(40,8);
        cin.getline(Username,20);
        cin.getline(Password,20);
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
                if(data[i] != Password[i-20]) return log();
            }
        }
    }
    pasFile.close();
    return username;
}

void login::sign()
{ 
    if(pasFile.fail()) pasFile.open(filename, ios::binary | ios::in | ios::out);
    if(pasFile.fail())
    {
        cout << "初始化，请重试！" << endl;
        getchar();
        exit(0);
    }
    char Username[20];
    char Password[20];
    char Data[40];
    //注册界面
    {
        cin.getline(Data,20);
        cin.getline(&Data[20],20);
    }
    pasFile.seekg(0L, ios::end);
    pasFile.write((char*)&Data,sizeof(Data));
    pasFile.close();
}

