//***************************************************************************
//*学生通讯录程序。编写一个程序，将下面的学生信息存储到文件中：
//*name：具有21个空间的字符数组。
//*age：一个整型变量。
//*address：具有51个空间的字符数组。
//*phone：具有14个空间的字符数组。
//*E-mail：具有51个空间的字符数组。
//*该程序具有一个菜单，便于用户完成以下操作：
//*1、向文件中增加记录。
//*2、显示文件中的所有记录。
//*3、修改任意一个记录。
//*4、按照姓名查找一个学生的记录。
//*5、删除某个学生的记录。
//*输入有效性检验：输入的年龄不能为负，也不能大于200。
//***************************************************************************
# include "iostream"
using namespace std;
# include "fstream"
# include "stdlib.h"
# include "iomanip"
# include "string.h"
# include "ctype.h"
struct info
{
	char name[21];
	int age;
	char address[51];
	char phone[14];
	char email[51];
}student[100];
void add(fstream&);
void show(fstream&);
void edit(fstream&);
void find(fstream&);
void delet(fstream&);
int main(void)
{
	fstream sdtsfile;
	int choice;
	sdtsfile.open("datafile.dat", ios::in | ios::out | ios::binary);
	if (sdtsfile.fail())
	{
		cout << "文件打开失败！" << endl;
		exit(0);
	}


	while (true)
	{
        cout << "1.向文件中增加记录。" << endl;
    	cout << "2.显示文件中的所有记录。" << endl;
	    cout << "3.修改任意一个记录。" << endl;
    	cout << "4.按照姓名查找一个学生的记录。" << endl;
    	cout << "5.删除某个学生的记录。" << endl << endl << endl << endl;
	    cout << "请输入你的选择(请输入1-5):";
        cin>>choice;
        cin.get();
		switch (choice)
		{
		case 1: add(sdtsfile); break;
		case 2: show(sdtsfile); break;
		case 3: edit(sdtsfile); break;
		case 4: find(sdtsfile); break;
		case 5: delet(sdtsfile); break;

		}
	}
	sdtsfile.close();
	return 0;
}
void add(fstream& file)
{
	info student;
	cin.ignore();
	cout << "请输入增加学生的信息：" << endl;
	cout << "姓名：";
	cin.getline(student.name, 21);
	cout << "年龄：";
	cin >> student.age;
	cin.ignore();
	cout << "联系地址：";
	cin.getline(student.address, 51);
	cout << "联系电话：";
	cin.getline(student.phone, 14);
	cout << "email：";
	cin.getline(student.email, 51);
	file.seekp(0, ios::end);
	file.write((char*)&student, sizeof(student));
	file.flush();
}
void show(fstream& file)
{
	info student[100];
	int i=0;
	file.seekg(0L, ios::beg);
	file.read((char*)&student[0], sizeof(student[0]));
	while (!file.eof())
	{
		cout << "姓名："; 
		cout << student[i].name << endl;
		cout << "年龄：";
		cout << student[i].age << endl;
		cout << "地址：";
		cout << student[i].address << endl;
		cout << "电话：";
		cout << student[i].phone << endl;
		cout << "email：";
		cout << student[i].email << endl << endl<<endl;
		i++;
		file.read((char*)&student[i], sizeof(student[i]));
	}
	cout << "显示完毕！" << endl;
	
}
void edit(fstream& file)
{
	info student[100];
	int a;
	file.clear();
	cout << "你想修改哪个人（0-54）？";
	cin >> a;
	cin.ignore();
	file.seekg(a * sizeof(student[a]), ios::beg);/*调整读指针*/
	file.read((char*)&student[a], sizeof(student[a]));/*将原来的的数据读出来*/
	cout << "姓名：" << student[a].name << endl;
	cout << "年龄:" << student[a].age << endl;
	cout << "地址：" << student[a].address << endl;
	cout << "电话:" << student[a].phone << endl;
	cout << "email:" << student[a].email << endl;
	cout << "请输入下面的新信息：" << endl;
	cout << "姓名:";
	cin.getline(student[a].name, 21);
	cout << "年龄：";
	cin >> student[a].age;
	cin.ignore();
	cout << "联系地址:";
	cin.getline(student[a].address, 51);
	cout << "联系电话:";
	cin.getline(student[a].phone, 14);
	cout << "email:";
	cin.getline(student[a].email, 51);
	file.seekp(a * sizeof(student[a]), ios::beg);
	file.write((char*)&student[a], sizeof(student[a]));
	file.flush();
}
void find(fstream &file)
{
	info student[100];
	char name[21];
	int a;
	file.clear();
	cout << "请输入你想查找学生的姓名：" << "  ";
	cin.getline(name, 21);
	for (a = 0; a < 100; a++)
	{
		file.seekg(0L, ios::beg);/*调整读指针*/
		file.read((char*)&student, sizeof(student));
		if(strcmp(name, student[a].name) == 0)
        {
			cout << "姓名：" << student[a].name << endl;
			cout << "年龄：" << student[a].age << endl;
			cout << "地址：" << student[a].address << endl;
			cout << "电话：" << student[a].phone << endl;
			cout << "email：" << student[a].email << endl;
		}
	}
}
	
void delet(fstream &file)/*delete有特殊含义！不能定义成delete！*/
{
	int i;
	char choice;
	file.clear();
	cout << "你想删除哪个人的信息（1-100）？";
	cin >> i;
	cin.ignore();
	file.seekg(0L, ios::beg);
	file.read((char*)student, sizeof(student));
	for (i;student[i].name[0] != '\0'; i++)
		student[i] = student[i + 1];i0=
		file.seekp(0L, ios::beg);
		file.write((char*)&student, sizeof(student));
		file.flush();
}