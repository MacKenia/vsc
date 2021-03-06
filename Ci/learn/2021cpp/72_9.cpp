#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//结构体
struct stu
{
    char name[21];
    int age;
    char address[51];
    char phone[14];
    char Email[51];
    bool operator==(const char *s)
    {
        return !(strcmp(s, name));
    }
}example;

//vector 容器
vector<stu> stud;
vector<stu>::iterator p;

//声明
int addRecord(vector<stu>::iterator=stud.end());

//添加学生数据函数
int addRecord(vector<stu>::iterator sp)
{
    cout << "请输入学生姓名: ";
    cin >> example.name;
    cout << "请输入学生年龄: ";
    cin >> example.age;
    cin.ignore(100,'\n');
    cout << "请输入学生地址: ";
    cin >> example.address;
    cout << "请输入学生电话: ";
    cin >> example.phone;
    cout << "请输入学生邮件地址: ";
    cin >> example.Email;
    if(example.age>200)
    {
        cout << "请重新输入输入学生年龄: ";
        cin >> example.age;
        cin.ignore();
    }
    stud.insert(sp,example);
    return 1;
}

//for_each函数
int show(stu stut)
{ 
    cout << "姓名: " << stut.name << endl
    << "年龄: " << stut.age << endl
    << "电话: " << stut.phone << endl
    << "地址: " << stut.address << endl
    << "邮件: " << stut.Email << endl << endl;
    return 1;
}

//显示记录
int showRecord()
{
    for_each(stud.begin(),stud.end(),show);
    return 1;
}

//修改学生记录
int modifyRecord()
{
    int no;
    cout << "输入需要修改的学生的序号: ";
    cin >> no;
    cin.ignore();
    p = stud.begin();
    no--;
    while(no--) p++;
    cout 
    << "你要修改的学生信息: " << endl
    << "姓名: " << p->name << endl
    << "年龄: " << p->age << endl
    << "地址: " << p->address << endl
    << "电话: " << p->phone << endl
    << "E-mail: " << p->Email << endl
    << "请录入新的信息: " << endl;
    stud.erase(p);
    addRecord(p);
    return 1;
}

//查找记录
int seekRecord()
{
    char ser[21];
    cout << "请输入学生姓名: ";
    cin >> ser;
    cin.ignore();
    p = find(stud.begin(),stud.end(),ser);
    cout << "姓名: " << p->name << endl
    << "年龄: " << p->age << endl
    << "地址: " << p->address << endl
    << "电话: " << p->phone << endl
    << "E-mail: " << p->Email << endl
    << endl;
    return 1;
}

//删除学生记录
int eraseRecord()
{
    char flag;
    cout << "现在进行删除操作, ";
    seekRecord();
    cout << "确定删除该学生吗？[Y/N]: ";
    cin >> flag;
    cin.ignore();
    if(flag == 'Y'|| flag == 'y')
    {
        stud.erase(p);
        cout << "删除成功";
    }
    return 1;
}

//主函数
int main()
{
    int choice, count = 0;
    bool flag = false;
    stu tmp = {"",0,"","",""};
    fstream file("a.dat",ios::in|ios::binary);
    if(file.fail())
    {
        cout << "打开失败!" << endl;
        exit(0);
    }
    else cout << "正在载入dat文件" << endl;
    // file.clear(); 
    // file.flush();
    // file.seekg(0L,ios::beg);
    while(!file.eof())
    {
        file.read((char *)&tmp,sizeof(tmp));
        if(file.fail()) break;
        stud.push_back(tmp);
        cout << "正在载入第" << ++count << "条数据" << endl;
        
    }
    cout << "*** 一共载入 " << count << " 条数据 ***" << endl;
    file.close();
    while(true)
    {
        cout << endl
        << "*********** 菜单 ************" << endl
        << "(1)向文件中增加记录" << endl 
        << "(2)显示文件中的所有记录" << endl 
        << "(3)修改任意的一个记录" << endl 
        << "(4)按照姓名查找一个学生记录" << endl 
        << "(5)删除某个学生的记录" << endl 
        << "(6)退出" << endl
        << "****************************" << endl
        << endl << "请输入数字: " ;
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1: addRecord();
                    break;     
            case 2: showRecord();
                    break;
            case 3: modifyRecord();
                    break;
            case 4: seekRecord();
                    break;
            case 5: eraseRecord();
                    break;
            case 6: flag = true;
                    break;
    }
    if(flag) break;
    cout << endl << "回车以继续";
    cin.get();
    }
    file.open("a.dat",ios::binary|ios::out);
    // file.seekp(1L, ios::beg);
    for(p = stud.begin();p != stud.end(); p++)
    {
        strcpy(tmp.name, p->name);
        tmp.age = p->age;
        strcpy(tmp.address, p->address);
        strcpy(tmp.phone, p->phone);
        strcpy(tmp.Email, p->Email);
        // show(tmp);
        file.write((char *)&tmp,sizeof(tmp));
    }
    file.close();
    return 0;
}
