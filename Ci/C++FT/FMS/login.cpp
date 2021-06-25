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
    {
        // 主界面
        int c = 300;
        lo.setbc("e0");
        lo.settop(32,8);
        lo.bw(40,12);
        cout << lo.title("好友管理系统");
        cout << lo.textb(38,10,"使用上下键选择，回车确认");
        cout << lo.texta(38,13,"1.登录");
        cout << lo.text(38,15,"2.注册");
        cout << lo.text(38,17,"3.退出");
        while(true)
        {
            lo.get();
            if(lo.button() == 2) c++;
            else if(lo.button() == 1) c--;
            else if(lo.button() == 0)
            {
                if(c%3==0) return signIn();
                else if(c%3==1) return signUp();
                else if(c%3==2) exit(1);
            }
            switch(abs(c)%3)
            {
                case 0:
                    cout << lo.texta(38,13,"1.登录");
                    cout << lo.text(38,15,"2.注册");
                    cout << lo.text(38,17,"3.退出");
                    lo.ccp(38,13);
                    break;
                case 1:
                    cout << lo.text(38,13,"1.登录");
                    cout << lo.texta(38,15,"2.注册");
                    cout << lo.text(38,17,"3.退出");
                    lo.ccp(38,15);
                    break;
                case 2:
                    cout << lo.text(38,13,"1.登录");
                    cout << lo.text(38,15,"2.注册");
                    cout << lo.texta(38,17,"3.退出");
                    lo.ccp(38,17);
                    break;
            }
        }
    }
}

char* login::signIn()
{
    pasFile.open(filename, ios::binary | ios::in);
    char input[40];
    char data[40];
    memset(input, 0, sizeof(input));
    memset(username, 0, sizeof(username));
    //登录界面
    lo.setbc("e0");
    lo.settop(32,8);
    lo.bw(40,12);
    cout << lo.title("登录");
    cout << lo.textb(50,9,"请登录");
    cout << lo.text(40,12,"用户：") << lo.input(47,12);
    cout << lo.text(40,14,"密码：") << lo.input(47,14);
    cout << lo.textb(50,16,"<登录>");
    lo.ccp(47,12);
    lo.color(240);
    cin.getline(input,20);
    strcpy(username,input);
    lo.ccp(47,14);
    cin.getline(&input[20],20);
    for(int i = 0; i<39; i++) input[i] += 1;
    cout << lo.textc(50,16,"<登录>");
    getchar();
    while(!pasFile.eof())
    {
        pasFile.read((char*)data, sizeof(data));
        if(pasFile.fail()) break;
        if(strcmp(data,input))
        {
            lo.setbc("c7");
            lo.settop(32,8);
            lo.bw(40,12);
            cout << lo.text(42,11,"用户名或错误，请重试!") << lo.textc(49,15,"<确定>");
            pasFile.close();
            lo.get();
            // pos po;
            return signIn();
        }
        else break;
    }
    pasFile.close();
    return username;
}

char* login::signUp()
{
    pasFile.open(filename, ios::binary | ios::in | ios::out);
    if(pasFile.fail())
    {
        cout << "初始化，请重试！" << endl;
        getchar();
        exit(0);
    }
    char Data[40];
    memset(Data, 0, sizeof(Data));
    { //注册界面
        lo.setbc("e0");
        lo.settop(32,8);
        lo.bw(40,13);
        lo.title("注册");
        cout << lo.textb(39,10,"请注册，并牢记用户名和密码");
        cout << lo.text(40,13,"用户：") << lo.input(47,13);
        cout << lo.text(40,15,"密码：") << lo.input(47,15);
        cout << lo.textb(50,18,"<登录>");
        lo.color(240);
        lo.ccp(47,13);
        cin.getline(Data,20);
        lo.ccp(47,15);
        cin.getline(&Data[20],20);
    }
    for(int i = 0; i < 39; i++) Data[i] += 1;
    pasFile.flush();
    pasFile.seekg(0L, ios::end);
    pasFile.write((char*)Data,sizeof(Data));
    {//注册成功界面
        lo.setbc("af");
        lo.settop(32,8);
        lo.bw(40,12);
        cout << lo.text(43,11,"注册成功，返回主页!") << lo.textc(49,15,"<确定>");
        lo.get();
    }
    pasFile.close();
    return log();
}
