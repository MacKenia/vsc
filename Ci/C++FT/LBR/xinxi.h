#ifndef XINXI_H
#define XINXI_H
#include"date.h"
#include"zhanghao.h"
#include"iostream"
#include<sstream>
using namespace std;
#include<string.h>
class xinxi:public Zhanghao
{
private:
	string sno;//ѧ��(13��)
	string bnumber;//ͼ����(10)
	string bname;//����(20)
	string lei;//1Ϊ��ͨ�࣬2Ϊ����ࣨ4���ַ���
	date ltime;//����ʱ�䣨15���ַ���
	int longth;//�ɽ�����(4)
	date lasttime;//��ٹ黹����(15)
	date btime;//�������ڣ�15���ַ��� ����ʱÿ��֮���һ��' ';
public:
	xinxi(string &a,int i)
	{
		sno.assign(a,0,13);
		lei = 1;
		longth = 30;
		date WW = ltime;
		lasttime = WW + longth;

	}
	void setdate()//������Ϣ
	{
		cout << "ͼ���ţ�";
		cin >> bnumber;
		cout << "\t������";
		cin>>bname;
		cout << "\n���1.��ͨ�� 2.����ࣩ��";
		cin>>lei;
		cout << "\t���ʱ�䣺";
		int a, b, c;
		cin >> a >> b >> c;
		ltime.setdate1(a,b,c);
		cout << ltime.getm() << ltime.getd();
		date WW = ltime;
		lasttime = WW + longth;
		cout << ltime.getm() << ltime.getd();
		cout << lasttime.getm() << lasttime.getd();
		if (lei == "��ͨ��")
			longth = 30;
		else longth = 7;
	}
	string getsno()
	{
		return sno;
	}
	string getbnumber()
	{
		return bnumber;
	}
	string getbname()
	{
		return bname;
	}
	string getlei()
	{
		return lei;
	}
	int getltimey()
	{
		return ltime.gety();
	}
	int getltimem()
	{
		return ltime.getm();
	}
	int getltimed()
	{
		return ltime.getd();
	}
	int getlasttimey()
	{
		return lasttime.gety();
	}
	int getlasttimem()
	{
		return lasttime.getm();
	}
	int getlasttimed()
	{
		return lasttime.getd();
	}
	int getlongth()
	{
		return longth;
	}
	int getbtimey()
	{
		return btime.gety();
	}
	int getbtimem()
	{
		return btime.getm();
	}
	int getbtimed()
	{
		return btime.getd();
	}
};
#endif // !XINXI_H