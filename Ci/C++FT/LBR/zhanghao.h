#ifndef ZHANGHAO_H
#define ZHANGHAO_H
#include<iostream>
using namespace std;
#include<string>
class Zhanghao
{
private:
	string number;//�˺ţ�ѧ�ţ�13λ+1��ĸ��/��ʦ�ţ�10λ+1��/����Ա��ţ�8λ+1��
	string secret;//����
	string name;//����(10)
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
	void changesecret()//�޸�����
	{
		while (1)
		{
			string change1, change2;
			cout << "�����������룺";
			getline(cin, change1);
			cout << "���ٴ����������룺";
			getline(cin, change2);
			if (change1 == change2)
			{
				secret = change1;
				cout << "�޸ĳɹ�";
				break;
			}
			else {
				cout << "�������벻һ��,���������룺";
				changesecret();
			}
			break;
		}
	}
};
#endif
