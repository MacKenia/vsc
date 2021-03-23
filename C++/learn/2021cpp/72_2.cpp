#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct stu{
    char name[21];
    int age;
    char address[51];
    char phone[14];
    char Email[51];
}example;
//vector 容器
vector<stu> stud;
//添加学生数据函数
int addRcord()
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
    }
    stud.push_back(example);
    return 1;
}

int show(stu stut){ 
    cout << "姓名: " << stut.name << endl
    << "年龄: " << stut.age << endl
    << "电话: " << stut.phone << endl
    << "地址: " << stut.address << endl
    << "邮件: " << stut.Email << endl << endl;
    return 1;
}

int showRcord()
{
    for_each(stud.begin(),stud.end(),show);
    return 1;
}

int main()
{
    int choice, count = 0;
    bool flag = false;
    stu tmp;
    fstream file("a.dat",ios::in|ios::out|ios::binary);
    if(file.fail()) cout << "打开失败!" << endl;
    else cout << "正在载入dat文件" << endl;
    file.clear();
    file.seekg(0L,ios::beg);
    while(!file.eof())
    {
        file.read((char *)&tmp,sizeof(tmp));
        stud.push_back(tmp);
        cout << "正在载入第" << ++count << "条数据" << endl;
    }
    cout << "一共载入" << count << "条数据";
    file.close();
    while(true)
    {
        cout << endl << endl 
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
        switch (choice) {
            case 1: addRcord();
                    break;     
            case 2: showRcord();
                    break;
            case 3: 
                    break;
            case 4: 
                    break;
            case 5: 
                    break;
            case 6: 
                    flag = true;
    }
    if(flag) break;
    cout << endl << "回车以继续";
    cin.ignore();
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
