#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct stu
{
    char name[21];
    int age;
    char address[51];
    char phone[14];
    char Email[51];
}example;
//vector 容器
vector<stu> stud;
//添加学生数据函数
int addRecord()
{
    cout << "请输入学生姓名：";
    cin >> example.name;
    cout << "请输入学生年龄：";
    cin >> example.age;
    cout << "请输入学生地址：";
    cin >> example.address;
    cout << "请输入学生电话：";
    cin >> example.phone;
    cout << "请输入学生邮件地址";
    cin >> example.Email;
    if(example.age>200)
    {
        cout << "请重新输入输入学生年龄；";
        cin >> example.age;
        cin.ignore();
    }
    stud.push_back(example);
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
    
    return 1;
}
//查找记录
int seekRecord()
{
    return 1;
}
//删除学生记录
int eraseRecord()
{
    vector<stu>::iterator e = stud.begin();
    int no = 0;
    cout << "请输入需要删除的学生序号(输入0删除最后一个): ";
    cin >> no;
    cin.ignore(100,'\n');
    if(!no) stud.pop_back();
    else
    {
        no--;
        while(no--) e++;
        e = stud.erase(e);
    }
    return 1;
}
//主函数
int main()
{
    int choice, count = 0;
    bool flag = false;
    stu tmp = {"",0,"","",""};
    fstream file("a.dat",ios::in|ios::out|ios::binary);
    if(file.fail()) cout << "打开失败!" << endl;
    else cout << "正在载入dat文件" << endl;
    file.clear();
    file.flush();
    file.seekg(0L,ios::beg);
    while(!file.eof())
    {
        file.read((char *)&tmp,sizeof(tmp));
        stud.push_back(tmp);
        cout << "正在载入第" << ++count << "条数据" << endl;
    }
    cout << "一共载入 " << count << " 条数据";
    file.close();
    while(true)
    {
        cout << endl
        << "*********** 菜单 ************" << endl
        << "(1)向文件中增加记录" << endl 
        << "(2)显示文件中的所有记录" << endl 
        << "(3)删除任意的一个记录" << endl 
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
    for(vector<stu>::iterator p = stud.begin();p != stud.end(); p++)
    {
        strcpy(tmp.name, p->name);
        tmp.age = p->age;
        strcpy(tmp.address, p->address);
        strcpy(tmp.phone, p->phone);
        strcpy(tmp.Email, p->Email);
        show(tmp);
        file.write((char *)&tmp,sizeof(tmp));
    }
    file.close();
    return 0;
}
