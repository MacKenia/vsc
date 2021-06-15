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
	string sno;//学号(13个)
	string bnumber;//图书编号(10)
	string bname;//书名(20)
	string lei;//1为普通类，2为珍贵类（4个字符）
	date ltime;//借书时间（15个字符）
	int longth;//可借日期(4)
	date lasttime;//最迟归还日期(15)
	date btime;//还书日期（15个字符） 存贮时每种之间隔一个' ';
public:
	xinxi(string &a,int i)
	{
		sno.assign(a,0,13);
		lei = 1;
		longth = 30;
		date WW = ltime;
		lasttime = WW + longth;

	}
	void setdate()//输入信息
	{
		cout << "图书编号：";
		cin >> bnumber;
		cout << "\t书名：";
		cin>>bname;
		cout << "\n类别（1.普通类 2.珍贵类）：";
		cin>>lei;
		cout << "\t借出时间：";
		int a, b, c;
		cin >> a >> b >> c;
		ltime.setdate1(a,b,c);
		cout << ltime.getm() << ltime.getd();
		date WW = ltime;
		lasttime = WW + longth;
		cout << ltime.getm() << ltime.getd();
		cout << lasttime.getm() << lasttime.getd();
		if (lei == "普通类")
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