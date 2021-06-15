#ifndef ZHANGHAO_H
#define ZHANGHAO_H
#include<iostream>
using namespace std;
#include<string>
class Zhanghao
{
private:
	string number;//账号（学号（13位+1字母）/教师号（10位+1）/管理员编号（8位+1）
	string secret;//密码
	string name;//姓名(10)
public:
	void xinxjian(string a, string b, string c)
	{
		number = a;
		secret = b;
		name = c;
	}
	void jinru(string& w)
	{
		if(w[0]=='S')
		{ 
			number = w.substr(0, 14);
			secret = w.substr(15, 6);
			name = w.substr(22, 10);
		}
		else if (w[0] == 'T')
		{
			number = w.substr(0, 11);
			secret = w.substr(12, 6);
			name = w.substr(19, 10);
		}
		else
		{
			number = w.substr(0, 9);
			secret = w.substr(10, 6);
			name = w.substr(17, 10);
		}
	}
	string getzhanghao()
	{
		return number;
	}
	string getsecret()
	{
		return secret;
	}
	string getname()
	{
		return name;
	}
	void changesecret()//修改密码
	{
		while (1)
		{
			string change1, change2;
			cout << "请输入新密码：";
			getline(cin, change1);
			cout << "请再次输入新密码：";
			getline(cin, change2);
			if (change1 == change2)
			{
				secret = change1;
				cout << "修改成功";
				break;
			}
			else {
				cout << "两次密码不一致,请重新输入：";
				changesecret();
			}
			break;
		}
	}
};
#endif
