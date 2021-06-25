#include "frd.h"
using namespace std;

void frd::funa(struct peo t)
{
    cout << "姓名：" << t.name << scr.endline();
    cout << "好友编号：" << t.num << scr.endline();
    cout << "性别：" << t.gender << scr.endline();
    cout << "等级：" << t.grader <<scr.endline();
    cout << "年龄：" << t.age << scr.endline();
    cout << "电话：" << t.tel << scr.endline();
    cout << "爱好：" << t.hobby << scr.endline() << scr.endline();
}

void frd::funb(struct peo t)
{
    if(!strcmp(t.gender,me.gender)) funa(t);
}

void frd::func(struct peo t)
{
    if(t.age == me.age) funa(t);
}

frd::frd(const char *filename)
{
    int i = 0;
    char load[5] = "/-\\|";
    Tmpdata = new char[2];
    scr.settop(0,0);
    frdFile.open(filename, ios::binary | ios::out | ios::in | ios::app);
    if(frdFile.fail())
    {
        cout << "文件打开失败，请重试！" << scr.endline();
        exit(0);
    }
    frdFile.read((char*)&me,sizeof(me));
    if(strcmp(me.name,filename)) createme();
    while(!frdFile.eof())
    {
        frdFile.read((char*)&fri, sizeof(fri));
        if(frdFile.fail()) break;
        vec.push_back(fri);
        cout <<"[" << load[i%4] << "]"<< "正在加载第" << vec.size() << "人的信息\r";
        Sleep(100);
    }
    frdFile.close();
}

void frd::addf()
{
    int c = 200;
    scr.setbc("e0");
    scr.settop(28,4);
    scr.bw(50,20);
    scr.title("添加好友");
    cout << scr.textb(36,6,"请输入好友信息后回车确认！") << scr.textb(52,6,"回车",114);
    cout << scr.textb(36,9,"姓名：") << scr.input(42,9,30);
    cout << scr.textb(36,11,"性别：") << scr.input(42,11,30);
    cout << scr.textb(36,13,"年龄：") << scr.input(42,13,30);
    cout << scr.textb(36,15,"电话：") << scr.input(42,15,30);
    cout << scr.textb(36,17,"爱好：") << scr.input(42,17,30);
    cout << scr.textb(40,20,"<确定>") << scr.textb(60,20,"<取消>");
    scr.color(240);
    scr.ccp(42,9);
    cin.getline(fri.name,25);
    scr.ccp(42,11);
    cin.getline(fri.gender,5);
    scr.ccp(42,13);
    cin.getline(fri.age,3);
    scr.ccp(42,15);
    cin.getline(fri.tel,12);
    scr.ccp(42,17);
    cin.getline(fri.hobby,255);
    fri.grader = 0;
    fri.num = (((int)fri.name[0])+(((int)fri.tel[0])*10)+(((int)fri.name[0])*100)+(rand() % 100000));
    cout << scr.textc(40,20,"<确定>") << scr.textb(60,20,"<取消>");
    while(true)
    {
        scr.get();
        if(scr.button() == 3) c--;
        else if(scr.button() == 4) c++;
        else if(scr.button() == 0)
        {
            if(!(c%2)) break;
            else
            {
                addf();
                return;
            }
        }
        switch(c%2)
        {
            case 0:
                cout << scr.textc(40,20,"<确定>") << scr.textb(60,20,"<取消>");
                break;
            case 1:
                cout << scr.textb(40,20,"<确定>") << scr.textc(60,20,"<取消>");
                break;
        } 
    }
    vec.push_back(fri);
    scr.setbc("af");
    scr.settop(32,8);
    scr.bw(40,12);
    scr.title("添加好友");
    cout << scr.textb(50,11,"成功!") << scr.textc(49,15,"<确定>");
    scr.get();
}

void frd::rmvf()
{
    int c = 200;
    char a[24] = "1.按姓名方式删除";
    char b[24] = "2.按编号方式删除";
    scr.setbc("e0");
    scr.settop(35,9);
    scr.bw(38,10);
    scr.title("删除好友");
    scr.textb(41,11,"请选则删除好友的方式：");
    scr.texta(41,13,a);
    scr.text(41,15,b);
    while(true)
    {
        scr.get();
        if(scr.button() == 1) c--;
        else if(scr.button() == 2) c++;
        else if(scr.button() == 0)
        {
            if(c%2)
            {
                //编号
                
                break;
            } 
            else
            {
                //姓名
                break;
            }
        }
        switch(!(c%2))
        {
            case 0:
                scr.texta(41,13,a);
                scr.text(41,15,b);
                break;
            case 1:
                scr.text(41,13,a);
                scr.texta(41,15,b);
                break;
        }
    }
    
}

void frd::rmvf(const char *s)
{
    char t;
    vp = secf(s);
    cout << "确定移除：" <<  vp->name  <<"吗？" << scr.endline()
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
    cout << "确定移除："  << vp->name  <<"吗？" << scr.endline()
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
    scr.cls();
    scr.setbc("e0");
    scr.settop(0,0);
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
    char a[21] = "1.通过编号修改";
    char b[21] = "2.通过姓名修改";
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
    vp = vec.end();
    vp--;
    funa(*vp);
    scr.get();
    me.num = vp->num;
    me.grader = vp->grader;
    strcpy(me.age,vp->age);
    strcpy(me.name,vp->name);
    strcpy(me.gender,vp->gender);
    strcpy(me.tel,vp->tel);
    strcpy(me.hobby,vp->hobby);
    vec.erase(vp);
    //界面
}

frd::~frd()
{
    cout << "xi";
    frdFile.open(me.name, ios::out);
    frdFile.write((char*)&me,sizeof(me));
    for(vp = vec.begin(); vp != vec.end(); vp++)
    {
        fri.num = vp->num;
        fri.grader = vp->grader;
        strcpy(fri.age,vp->age);
        strcpy(fri.name,vp->name);
        strcpy(fri.gender,vp->gender);
        strcpy(fri.tel,vp->tel);
        strcpy(fri.hobby,vp->hobby);
        funa(fri);
        frdFile.write((char*)&fri,sizeof(fri));
        cout << "正在写入第" << vp - vec.begin() + 1 << "条记录\r";
        Sleep(100);
    }
    frdFile.close();
    vec.clear();
    delete []Tmpdata;
    cout << "end";
    getchar();
}


