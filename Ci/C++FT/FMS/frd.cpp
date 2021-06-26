#include "frd.h"
// using namespace std;

void frd::funa(struct peo t)
{
    cout << "姓名：" << scr.color(116) << t.name  << scr.color(112) << scr.endline();
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
        i++;
    }
    frdFile.close();
}

void frd::addf()
{
    int co = 200;
    scr.setbc("e0");
    scr.settop(28,4);
    scr.bw(50,20);
    scr.title("添加信息");
    cout << scr.textb(36,6,"请输入相关信息后回车确认！") << scr.textb(52,6,"回车",114);
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
        if(scr.button() == 3) co--;
        else if(scr.button() == 4) co++;
        else if(scr.button() == 0)
        {
            if(!(co%2)) break;
            else
            {
                addf();
                return;
            }
        }
        switch(co%2)
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
    scr.title("添加信息");
    cout << scr.textb(50,11,"成功!") << scr.textc(49,15,"<确定>");
    scr.get();
}

void frd::rmvf()
{
    int co = 300;
    char a[24] = "1.按姓名方式删除";
    char b[24] = "2.按编号方式删除";
    char c[9] = "3.取消";
    scr.setbc("e0");
    scr.settop(35,9);
    scr.bw(38,12);
    scr.title("删除好友");
    scr.textb(41,11,"请选则删除好友的方式：");
    scr.texta(41,13,a);
    scr.text(41,15,b);
    scr.text(41,17,c);
    while(true)
    {
        scr.get();
        if(scr.button() == 1) co--;
        else if(scr.button() == 2) co++;
        else if(scr.button() == 0)
        {
            if(co%3 == 0)
            {
                //姓名
                char name[25];
                char d[] = "请输入姓名：";
                scr.setbc("e0");
                scr.settop(36,12);
                scr.bw(34,6);
                scr.title("以姓名删除好友");
                scr.textb(40,15,d) << scr.input(52,15,15);
                scr.ccp(52,15);
                cin.getline(name,25);
                rmvf(secf(name));
            } 
            else if(co%3 == 1)
            {
                //编号
                char d[] = "请输入编号：";
                int num;
                scr.setbc("e0");
                scr.settop(36,12);
                scr.bw(34,6);
                scr.title("以编号删除好友");
                scr.textb(40,15,d) << scr.input(52,15,15);
                scr.ccp(52,15);
                cin >> num;
                rmvf(secf(num));
            }
            else if(co%3 == 2) return;
        }
        switch(co%3)
        {
            case 0:
                scr.texta(41,13,a);
                scr.text(41,15,b);
                scr.text(41,17,c);
                break;
            case 1:
                scr.text(41,13,a);
                scr.texta(41,15,b);
                scr.text(41,17,c);
                break;
            case 2:
                scr.text(41,13,a);
                scr.text(41,15,b);
                scr.texta(41,17,c);
        }
    }
    
}

void frd::rmvf(vector<peo>::iterator p)
{
    int co = 200;
    scr.setbc("c7");
    scr.settop(29,4);
    scr.bw(50,22);
    scr.title("删除");
    scr.textb(35,6,"确定删除这个人吗?");
    scr.textb(39,6,"删除",116);
    scr.ccp(37,8);
    scr.settop(37,8);
    if(p != vec.end())
    {//显示信息
        cout << scr.color(240) << "姓名："  << scr.color(112) << " " << scr.color(15)  << p->name << scr.endline() << scr.endline();
        cout << scr.color(240) << "好友编号：" << scr.color(112) << " " << scr.color(15)  << p->num << scr.endline() << scr.endline();
        cout << scr.color(240) << "性别：" << scr.color(112) << " " << scr.color(15)  << p->gender << scr.endline() << scr.endline();
        cout << scr.color(240) << "等级：" << scr.color(112) << " " << scr.color(15)  << p->grader <<scr.endline() << scr.endline();
        cout << scr.color(240) << "年龄：" << scr.color(112) << " " << scr.color(15)  << p->age << scr.endline() << scr.endline();
        cout << scr.color(240) << "电话：" << scr.color(112) << " " << scr.color(15)  << p->tel << scr.endline() << scr.endline();
        cout << scr.color(240) << "爱好：" << scr.color(112) << " " << scr.color(15)  << p->hobby << scr.endline() << scr.endline();
    }
    else
    {
        scr.setbc("c7");
        scr.settop(32,8);
        scr.bw(40,12);
        cout << scr.textb(45,11,"未查找到此人!") << scr.textc(49,15,"<确定>");
        scr.get();
        return;
    }
    cout << scr.textc(40,23,"<确定>") << scr.textb(60,23,"<取消>");
    while(true)
    {
        scr.get();
        if(scr.button() == 3) co--;
        else if(scr.button() == 4) co++;
        else if(scr.button() == 0)
        {
            if(!(co%2)) break;
            else return;
        }
        switch(co%2)
        {
            case 0:
                cout << scr.textc(40,23,"<确定>") << scr.textb(60,23,"<取消>");
                break;
            case 1:
                cout << scr.textb(40,23,"<确定>") << scr.textc(60,23,"<取消>");
                break;
        } 
    }
    vec.erase(p);
    scr.setbc("af");
    scr.settop(32,8);
    scr.bw(40,12);
    cout << scr.textb(48,11,"删除成功!") << scr.textc(49,15,"<确定>");
    scr.get();
}

void frd::shwf()
{
    int co = 400;
    char all[21] = "1.展示全部好友";
    char gen[21] = "2.展示同性好友";
    char ag[21] = "3.展示同龄好友";
    char cn[9] = "4.取消";
    scr.setbc("e0");
    scr.settop(35,9);
    scr.bw(38,14);
    scr.title("查看好友");
    scr.textb(41,11,"选择展示方式：");
    scr.texta(41,13,all);
    scr.text(41,15,gen);
    scr.text(41,17,ag);
    scr.text(41,19,cn);
    while(true)
    {
        scr.get();
        if(scr.button() == 1) co--;
        else if(scr.button() == 2) co++;
        else if(scr.button() == 0)
        {
            if(co%4 == 0) 
            {
                show();
                return;
            }
            else if(co%4 == 1)
            {
                show(1);
                return;
            }
            else if(co%4 == 2)
            {
                show(2);
                return;
            }
            else if(co%4 == 3) return;
        }
        switch(co%4)
        {
            case 0:
                scr.texta(41,13,all);
                scr.text(41,15,gen);
                scr.text(41,17,ag);
                scr.text(41,19,cn);
                break;
            case 1:
                scr.text(41,13,all);
                scr.texta(41,15,gen);
                scr.text(41,17,ag);
                scr.text(41,19,cn);
                break;
            case 2:
                scr.text(41,13,all);
                scr.text(41,15,gen);
                scr.texta(41,17,ag);
                scr.text(41,19,cn);
                break;
            case 3:
                scr.text(41,13,all);
                scr.text(41,15,gen);
                scr.text(41,17,ag);
                scr.texta(41,19,cn);
                break;
        }
    }
}

void frd::show(int w)
{
    scr.setbc("e0");
    scr.settop(1,1);
    scr.bw(106,29);
    scr.title("所有好友");
    scr.settop(5,3);
    scr.ccp(5,3);
    if(vec.size() <= 15)
    {
        switch(w)
        {
            case 0:
                for(vp = vec.begin(); vp < vec.end(); vp++) funa(*vp);
                break;
            case 1:
                scr.title("同性好友");
                for(vp = vec.begin(); vp < vec.end(); vp++) funb(*vp);
                break;
            case 2:
                scr.title("同龄好友");
                for(vp = vec.begin(); vp < vec.end(); vp++) func(*vp);
                break;
        }
        cout << scr.textc(50,27,"<退出>");
        getchar();
        return;
    }
    else
    {
        int i;
        while(true)
        {

        }
        cout << scr.textc(40,27,"<←上一页>") << scr.ccp(49,27) << scr.color(207) << i << scr.textb(60,27,"<下一页→>");
        cout << scr.textc(40,27,"<回车退出>") << scr.textb(60,27,"<下一页→>");
    }
    pos pp;
}

void frd::modf()
{
    int co = 300;
    char a[21] = "1.通过编号修改";
    char b[21] = "2.通过姓名修改";
    char c[9] = "3.取消";
    scr.setbc("e0");
    scr.settop(32,8);
    scr.bw(40,12);
    scr.title("修改信息");
    scr.textb(38,10,"选择修改方式：");
    scr.texta(38,13,a);
    scr.text(38,15,b);
    scr.text(38,17,c);
    while(true)
    {
        scr.get();
        if(scr.button() == 1) co--;
        else if(scr.button() == 2) co++;
        else if(scr.button() == 0)
        {
            if(co%3 == 0)
            {
                char d[] = "请输入编号：";
                int num;
                scr.setbc("e0");
                scr.settop(36,12);
                scr.bw(34,6);
                scr.title("以编号修改好友");
                scr.textb(40,15,d) << scr.input(52,15,15);
                scr.ccp(52,15);
                cin >> num;
                modf(secf(num));
            }
            else if(co%3 == 1)
            {
                char name[25];
                char d[] = "请输入姓名：";
                scr.setbc("e0");
                scr.settop(36,12);
                scr.bw(34,6);
                scr.title("以姓名修改好友");
                scr.textb(40,15,d) << scr.input(52,15,15);
                scr.ccp(52,15);
                cin.getline(name,25);
                modf(secf(name));
            }
            else if(co%3 == 2) return;
        }
        switch (co%3)
        {
        case 0:
            scr.texta(38,13,a);
            scr.text(38,15,b);
            scr.text(38,17,c);
            break;
        case 1:
            scr.text(38,13,a);
            scr.texta(38,15,b);
            scr.text(38,17,c);
            break;
        case 2:
            scr.text(38,13,a);
            scr.text(38,15,b);
            scr.texta(38,17,c);
            break;
        
        }
    }
}

void frd::modf(vector<peo>::iterator p)
{
    funa(*p);
    getchar();
    //界面
    int co = 200;
    scr.setbc("e0");
    scr.settop(28,4);
    scr.bw(50,20);
    scr.title("修改信息");
    cout << scr.textb(36,6,"请输入相关信息后回车确认！") << scr.textb(52,6,"回车",114);
    cout << scr.textb(36,9,"姓名：") << scr.input(42,9,30) << scr.textb(42,9,p->name,240);
    cout << scr.textb(36,11,"性别：") << scr.input(42,11,30) << scr.textb(42,11,p->gender,240);
    cout << scr.textb(36,13,"年龄：") << scr.input(42,13,30) << scr.textb(42,13,p->age,240);
    cout << scr.textb(36,15,"电话：") << scr.input(42,15,30) << scr.textb(42,15,p->tel,240);
    cout << scr.textb(36,17,"爱好：") << scr.input(42,17,30) << scr.textb(42,17,p->hobby,240);
    cout << scr.textb(40,20,"<确定>") << scr.textb(60,20,"<取消>");
    scr.color(240);
    scr.ccp(42,9);
    cin.getline(fri.name,25);
    cout << endl << "[" << (int)fri.name[0] << "]" << endl;
    cout << endl << "[" << (int)fri.name[1] << "]" << endl;
    cout << endl << "[" << (int)fri.name[2] << "]" << endl;
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
        if(scr.button() == 3) co--;
        else if(scr.button() == 4) co++;
        else if(scr.button() == 0)
        {
            if(!(co%2)) break;
            else
            {
                addf();
                return;
            }
        }
        switch(co%2)
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
    scr.title("添加信息");
    cout << scr.textb(50,11,"成功!") << scr.textc(49,15,"<确定>");
    scr.get();
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
    int i = 0;
    char load[5] = "/-\\|";
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
        cout <<"\r[" << load[i%4] << "]"<< "正在写入第" << vp - vec.begin() + 1 << "条记录";
        i++;
        Sleep(100);
    }
    frdFile.close();
    vec.clear();
    delete []Tmpdata;
    cout << "end";
    getchar();
}


