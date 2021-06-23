#include "frd.h"
using namespace std;


void func(struct peo t)
{
    cout << "姓名：" << t.name << endline();
    cout << "性别：" ;
    if(t.gander) cout << "男" << endline();
    else cout << "" << endline();
    cout << "年龄：" << t.age << endline();
    cout << "电话：" << t.tel << endline();
    cout << "爱好：" << t.hobby << endline();
}

frd::frd(const char *filename)
{
    int i = 0;
    frdFile.open(filename, ios::binary | ios::out | ios::in);
    if(frdFile.fail())
    {
        cout << "文件打开失败，请重试！" << endl;
        exit(0);
    }
    while(frdFile.eof())
    {
        if(!i)
        {
            frdFile.read((char*)&me,sizeof(me));
            if(!strcmp(me.name,filename))
            {
                vec.push_back(me);
                createme();
            }
        }
        frdFile.read((char *)&fri, sizeof(fri));
        vec.push_back(fri);
        cout << "正在加载第" << vec.size() << "人的信息\r";
    }
    frdFile.close();
}

void frd::addf()
{
    cout << "姓名：";
    cin.getline(fri.name);
}

void frd::rmvf(const char *s)
{
    char t;
    vp = find(vec.begin(),vec.end(),s);
    cout << "确定移除：" << color() << vp->name << color() <<"吗？" << endl
    << "回车确认，输入n放弃：";
    getchar(t);
    cin.ignore();
    if(t == '\n')
    {
        vec.erase(vp);
        cout << "删除成功";
    }
}

void frd::rmvf(int a)
{
    char t;
    vp = find(vec.begin(),vec.end(),a);
    cout << "确定移除：" << color() << vp->name << color() <<"吗？" << endl
    << "回车确认，输入n放弃：";
    getchar(t);
    cin.ignore();
    if(t == '\n')
    {
        vec.erase(vp);
        cout << "删除成功";
    }
}

void frd::shwf()
{
    cout << sc::ccp() << "选择展示方式："
    << sc::cpp()
}

void frd::showall()
{
    for_each(vec.begin(),vec.end(),func())
}

void frd::genders()
{

}

void frd::ages()
{

}

void mod()
{

}

void frd::modf(const char *s)
{
    char t;
    cout <<
}

void frd::mod(int a)
{

}

void frd::secf(const char *s)
{

}

void frd::secf(int a)
{

}

void frd::createme()
{

}

frd::~frd()
{
    frdfile.close();
    vec.clear();
}


