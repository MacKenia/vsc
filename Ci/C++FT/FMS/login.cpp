#include "login.h"
using namespace std;

login::login()
{
    pasFile.open(filename, ios::binary | ios::in | ios::out | ios::app);
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
        lo.settop(32,8);
        lo.bw(40,12);
        cout << lo.title("登录");
        cout << lo.text(50,9,"请登录");
        cout << lo.text(40,12,"用户：") << lo.input(47,12);
        cout << lo.text(40,14,"密码：") << lo.input(47,14);
        cout << lo.text(43,17,"登录") << lo.text(58,17,"注册");
        lo.ccp(0,0);
        //cin.getline(Username,20);
        //cin.getline(Password,20);
    }
    while(0)
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

