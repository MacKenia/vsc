#include <iostream>
#include "frd.h"
using namespace std;

int main()
{
    sc mw("好友管理系统");
    login lo;
    mw.setW(110,18);
    cout << "              ,----------------,              ,---------," << endl;
    cout << "         ,-----------------------,          ,\"        ,\"|" << endl;
    cout << "       ,\"                      ,\"|        ,\"        ,\"  |" << endl;
    cout << "      +-----------------------+  |      ,\"        ,\"    |" << endl;
    cout << "      |  .-----------------.  |  |     +---------+      |" << endl;
    cout << "      |  |                 |  |  |     | -==----'|      |" << endl;
    cout << "      |  |  WELLCOME to    |  |  |     |         |      |" << endl;
    cout << "      |  |  Friends Manage |  |  |/----|`---=    |      |" << endl;
    cout << "      |  |  System  !      |  |  |   ,/|==== ooo |      ;" << endl;
    cout << "      |  |                 |  |  |  // |(((( [33]|    ,\"" << endl;
    cout << "      |  `-----------------'  |,\" .;'| |((((     |  ,\"" << endl;
    cout << "      +-----------------------+  ;;  | |         |,\"" << endl;
    cout << "         /_)______________(_/  //'   | +---------+" << endl;
    cout << "    ___________________________/___  `," << endl;
    cout << "   /  oooooooooooooooo  .o.  oooo /,   \\,\"-----------" << endl;
    cout << "  / ==ooooooooooooooo==.o.  ooo= //   ,`\\--{)B     ,\"" << endl;
    cout << " /_==__==========__==_ooo__ooo=_/'   /___________,\"" << endl;
    mw.textb(75,9,"[回车进入系统]");
    mw.get();
    mw.setW(110,32);
    frd user(lo.log());
    int co = 500;
    char a[] = "1.显示好友信息";
    char b[] = "2.修改好友信息";
    char c[] = "3.删除好友信息";
    char d[] = "4.添加好友";
    char e[] = "5.退出";
    user.showme();
    mw.setbc("e0");
    mw.settop(35,9);
    mw.bw(38,16);
    mw.title("好友管理系统");
    mw.ccp(2,9);
    mw.textb(41,11,"使用上下键选择，回车确认");
    mw.text(41,15,b);
    mw.text(41,17,c);
    mw.text(41,19,d);
    mw.text(41,21,e);
    mw.texta(41,13,a);
    while(true)
    {
        mw.get();
        if(mw.button() == 1) co--;
        else if(mw.button() == 2) co++;
        else if(mw.button() == 0)
        {
            if(co%5 == 0)
            {
                user.shwf();
                mw.setbc("e0");
                mw.settop(35,9);
                mw.bw(38,14);
                mw.title("好友管理系统");
                mw.textb(41,11,"使用上下键选择，回车确认");
                mw.texta(41,13,a);
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,19,d);
                mw.text(41,21,e);
            }
            else if(co%5 == 1)
            {
                user.modf();
                mw.setbc("e0");
                mw.settop(35,9);
                mw.bw(38,14);
                mw.title("好友管理系统");
                mw.textb(41,11,"使用上下键选择，回车确认");
                mw.texta(41,13,a);
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,19,d);
            }
            else if(co%5 == 2)
            {
                user.rmvf();
                mw.setbc("e0");
                mw.settop(35,9);
                mw.bw(38,14);
                mw.title("好友管理系统");
                mw.textb(41,11,"使用上下键选择，回车确认");
                mw.texta(41,13,a);
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,19,d);
            }
            else if(co%5 == 3)
            {
                user.addf();
                mw.setbc("e0");
                mw.settop(35,9);
                mw.bw(38,14);
                mw.title("好友管理系统");
                mw.textb(41,11,"使用上下键选择，回车确认");
                mw.texta(41,13,a);
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,19,d);
            }
            else break;
        }
        switch(co%5)
        {
            case 0:
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,19,d);
                mw.text(41,21,e);
                mw.texta(41,13,a);
                break;
            case 1:
                mw.text(41,13,a);
                mw.text(41,17,c);
                mw.text(41,19,d);
                mw.text(41,21,e);
                mw.texta(41,15,b);
                break;
            case 2: 
                mw.text(41,13,a);
                mw.text(41,15,b);
                mw.text(41,19,d);
                mw.text(41,21,e);
                mw.texta(41,17,c);
                break;
            case 3:
                mw.text(41,13,a);
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,21,e);
                mw.texta(41,19,d);
                break;
            case 4:
                mw.text(41,13,a);
                mw.text(41,15,b);
                mw.text(41,17,c);
                mw.text(41,19,d);
                mw.texta(41,21,e);
                break;
        }
    }
}