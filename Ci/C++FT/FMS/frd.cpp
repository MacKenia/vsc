#include "frd.h"
using namespace std;
 

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
    file.close();
}

void frd::addf()
{

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


