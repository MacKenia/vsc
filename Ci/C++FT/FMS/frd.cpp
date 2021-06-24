#include "frd.h"
using namespace std;

void each(vector<peo>::iterator b, vector<peo>::iterator e,void (*funca)(struct peo))
{
    for(; b < e; b++)
    {
        funca(*b);
    }
}

void frd::funa(struct peo t)
{
    cout << "姓名：" << t.name << endl;
    cout << "好友编号：" << t.num << endl;
    cout << "性别：" << t.gender << endl;
    cout << "年龄：" << t.age << endl;
    cout << "电话：" << t.tel << endl;
    cout << "爱好：" << t.hobby << endl;
}

void frd::funb(struct peo t)
{
    if(!strcmp(t.gender,me.gender))
    {
        cout << "姓名：" << t.name << endl;
        cout << "好友编号：" << t.num << endl;
        cout << "性别：" << t.gender << endl;
        cout << "年龄：" << t.age << endl;
        cout << "电话：" << t.tel << endl;
        cout << "爱好：" << t.hobby << endl;
    }
}

void frd::func(struct peo t)
{
    if(t.age == me.age)
    {
        cout << "姓名：" << t.name << endl;
        cout << "好友编号：" << t.num << endl;
        cout << "性别：" << t.gender << endl;
        cout << "年龄：" << t.age << endl;
        cout << "电话：" << t.tel << endl;
        cout << "爱好：" << t.hobby << endl;
    }
}

frd::frd(const char *filename)
{
    int i = 0;
    frdFile.open(filename, ios::binary | ios::out | ios::in | ios::app);
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
    if(!frdFile.eof()) createme();
    frdFile.close();
}

void frd::addf()
{
    cout << "姓名：";
    cin.getline(fri.name,25);
    cout << "性别：";
    cin.getline(fri.gender,5);
    cout << "年龄：";
    cin >> fri.age;
    cin.ignore();
    cout << "电话：";
    cin.getline(fri.tel,12);
    cout << "爱好：";
    cin.getline(fri.hobby,255);
    fri.grader = 0;
    fri.num = (((int)fri.name[0])+(((int)fri.tel[0])*10)+(((int)fri.name[0])*100)+(rand() % 100000));
    cout << "确认你输入的信息，回车来确认：" << endl;
    funa(fri);
    getchar();
    vec.push_back(fri);
    cout << "成功！";
}


void frd::rmvf()
{
    char a[24] = "1.按姓名方式删除";
    char b[24] = "2.按编号方式删除";
    cout << "请选则删除好友的方式：";
}

void frd::rmvf(const char *s)
{
    char t;
    vp = secf(s);
    cout << "确定移除：" <<  vp->name  <<"吗？" << endl
    << "回车确认，输入n放弃：";
    t = getchar();
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
    vp = secf(a);
    cout << "确定移除："  << vp->name  <<"吗？" << endl
    << "回车确认，输入n放弃：";
    t = getchar();
    cin.ignore();
    if(t == '\n')
    {
        vec.erase(vp);
        cout << "删除成功";
    }
}

void frd::shwf()
{
    char all[21] = "1.展示全部好友";
    char gen[21] = "2.展示同性好友";
    char ag[21] = "3.展示同龄好友";
    cout << "选择展示方式：" ;
    cout << all;
    cout << gen;
    cout << ag;
    //界面
}

void frd::showall()
{
    for(vp = vec.begin(); vp < vec.end(); vp++)
    {
        funa(*vp);
    }
}

void frd::genders()
{
    for(vp = vec.begin(); vp < vec.end(); vp++)
    {
        funb(*vp);
    }
}

void frd::ages()
{
    for(vp = vec.begin(); vp < vec.end(); vp++)
    {
        func(*vp);
    }
}

void mod()
{
    char a[] = "1.通过编号修改";
    char b[] = "2.通过姓名修改";
    cout << "选择修改方式：";
    //界面
}

void frd::modf(const char *s)
{
    cout << "这是你要修改的信息吗？";
    vp = secf(s);
    funa(*vp);
    //界面
    vec.erase(vp);
    addf();
}

void frd::modf(int a)
{
    cout << "这是你要修改的信息吗？";
    vp = secf(a);
    funa(*vp);
    //界面
    vec.erase(vp);
    addf();
}

vector<peo>::iterator frd::secf(const char *s)
{
    vector<peo>::iterator p;
    p = find(vec.begin(),vec.end(),s);
    return p;
}

vector<peo>::iterator frd::secf(int a)
{
    vector<peo>::iterator p;
    p = find(vec.begin(),vec.end(),a);
    return p;
}

void frd::createme()
{
    cout << "你还没有个人信息，请先创建：";
    addf();
    //界面
}

frd::~frd()
{
    cout << "ix";
    if(frdFile.fail()) frdFile.open(me.name, ios::out);
    frdFile.write((char*)&me,sizeof(me));
    for(vp = vec.begin(); vp != vec.end(); vp++)
    {
        fri.num = vp->num;
        fri.age = vp->age;
        fri.grader = vp->grader;
        strcpy(fri.name,vp->name);
        strcpy(fri.gender,vp->gender);
        strcpy(fri.tel,vp->tel);
        strcpy(fri.hobby,vp->hobby);
        frdFile.write((char*)&fri,sizeof(fri));
        cout << "正在写入第" << vp - vec.begin() << "条记录\r";
    }
    frdFile.close();
    vec.clear();
}


