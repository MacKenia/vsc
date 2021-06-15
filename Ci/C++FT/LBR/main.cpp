#include<fstream>
#include<string.h>
#include<stdlib.h>
#include"zhanghao.h"
#include"xinxi.h"
#include"date.h"
#include<iostream>
#include<conio.h>
#include<string>
fstream dateFile;
using namespace std;
void writerecord(xinxi XX, int n)//将借书信息写入文件
{
	dateFile.seekp(0L, ios::end);
	dateFile << XX.getsno() << ' '
		<< XX.getbnumber() << ' '
		<< XX.getbname() << ' '
		<< XX.getlei() << ' '
		<< XX.getltimey() << "/"
		<< XX.getltimem() << "/"
		<< XX.getltimed() << ' '
		<< XX.getlongth()<<' '
		<<XX.getlasttimey()<<"/"
		<<XX.getlasttimem()<<"/"
		<<XX.getlasttimed()<<' '
		<< "暂未还书" << endl;
}
int pos(string T, string P, int n)//找第几次出现的某个字符的位置
{
	if (n == 0)return -1;//相当于没找
	int count = 0;
	unsigned begined = 0;
	while ((begined = T.find(P, begined)) != string::npos) {
		count++;
		begined += P.length();
		if (n == count) {
			return begined - 1;
		}
	}
	return -2;//意味着没有那么多次
}
int main()
{
	int i;//身份编号
	string d, d1;//d为输入的账户号、密码，d1为从文件中提取的账户号、密码
	string z;//z为读出的学号
	string read[100];
	cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
	cout << "≈                                            ≈" << endl;
	cout << "≈请选择您的身份：1.学生                      ≈" << endl;
	cout << "≈                2.教师                      ≈" << endl;
	cout << "≈                3.管理员                    ≈" << endl;
	cout << "≈                                            ≈" << endl;
	cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
	cin >> i;
	cin.ignore();
	cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
	cout << "≈                                            ≈" << endl;
	cout << "≈    学号/教师号/管理员号：                  ≈" << endl;
	cout << "≈                    密码：                  ≈" << endl;
	cout << "≈                                            ≈" << endl;
	cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
	cout << "       *账号和密码，中间用一个空格分开：\n";
	getline(cin, d);//从键盘输入学号、密码
	cin.clear();
	while (1)
	{
		if (i == 1)
			d.insert(0, "S");//在d的最前面加入S
		else
		{
			if (i == 2)
				d.insert(0, "T");//在d的最前面加入T
			else d.insert(0, "M");//在d的最前面加入M
		}
		dateFile.seekp(0L, ios::beg);
		cin.clear();
		dateFile.open("zhanghao.txt", ios::in);
		if (dateFile.fail())
		{
			cout << "文件打开失败";
			exit(0);
		}
		while (!dateFile.eof())
		{
			char t[255];
			dateFile.getline(t, 255); //从文件中读取一行内容存入d1中
			d1.erase();
			d1.append(t);
			if (dateFile.fail())
			{
				cout << "读取失败";
				break;
			}
			
			if (d == d1)//重复读，验证
			{
				cout << "登录成功！";
				if (i == 1)
					z.assign(d, 1, 13);//将d的学号赋值给z//只能读第一行，不换行？？？？
				if (i == 2)
					z.assign(d, 1, 10);
				if (i == 3)
					z.assign(d, 1, 8);
				break;
			}
			break;
		}
		if (dateFile.eof())
		{
			cout << "未登录成功";
			cout << "请重新输入账号和密码";
			cin.ignore();
			getline(cin, d);
		}
		else break;
	}
	dateFile.close();
	system("pause");  //按任意键继续
	//开始进入主体
	switch (i)
	{
	case 1:
	{
		cout << "请选择操作：1.修改密码 2.查询借书信息：\n";
		int a;
		cin >> a;
		if (a == 1)
		{
			string yuan, gai1, gai2;
			cout << "请输入原密码：";
			cin >> yuan;
			if (yuan.compare(15, 6, d1) == 0)
			{
				cout << "验证成功";
				cout << "请输入新密码：";
				cin >> gai1;
				cout << "请再一次输入新密码：";
				cin >> gai2;
				if (gai1 == gai2)
				{
					d1.replace(15, 6, gai1);
					dateFile.open("zhanghao.txt", ios::in | ios::app);
					//将原来的记录删除？？？？
					getline(cin, d1);
					dateFile.close();
					cout << "修改成功";
				}
			}
			else cout << "密码错误，若忘记密码，请联系管理员";
		}
		else
		{
			int y;
			dateFile.open("student.txt", ios::in);
			if (dateFile.fail())
			{
				cout << "进入失败\n";
				exit(0);
			}
			while (!dateFile.eof())
			{
				char z1[15];
				while (1)
				{
					for (y = 0;;)
					{
						getline(dateFile, read[y], '\n');
						if (dateFile.fail())
						{
							cout << "借书信息读取失败！";
							break;
						}
						if (read[y].compare(1, 13, z) == 0)//read[y]中1-13的字符与z字符串是否相等
							y++;
						//比较read的学号与z中的账号，相同则y自增
						if (y == 0) cout << "暂无借书记录\n";
						else cout << "共" << y << "条记录";
					}
				}
			}
			cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
			cout << "≈                                            ≈" << endl;
			cout << "≈请选择您先要查询类别：1.图书编号            ≈" << endl;
			cout << "≈                      2.借书日期            ≈" << endl;
			cout << "≈                      3.还书日期            ≈" << endl;
			cout << "≈                      4.书名                ≈" << endl;
			cout << "≈                      5.书类                ≈" << endl;
			cout << "≈                                            ≈" << endl;
			cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
			int k;
			cin >> k;
			switch (k)
			{
			case 1:
			{
				string bian;
				int r;
				cout << "请输入图书编号：";
				getline(cin, bian);
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(14, 10, bian) == 0)
							cout << "图书编号：" << read[y].substr(14, 10)//截取图书编号
							<< "书名：" << read[y].substr(25, 20) << '\t'
							<< "类别：" << read[y].substr(46, 4) << '\t'
							<< "借书日期：" << read[y].substr(51, 15) << '\t'
							<< "可借天数：" << read[y].substr(67, 4) << '\t'
							<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
							<< "还书日期：" << read[y].substr(88, 15) << endl;
				}
				cout << "共" << r << "条记录";
				dateFile.close();
				break;
			}
			case 2:
			{
				int r;
				string jie;
				date jieshu;
				int y, m, d;
				cout << "请输入想要查询的借书日期：";
				cin >> y >> m >> d;
				jieshu.setdate1(y, m, d);
				jie = y + '/' + m + '/' + d;
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(49, 15, jie) == 0)
							cout << "图书编号：" << read[y].substr(14, 10)
							<< "书名：" << read[y].substr(25, 20) << '\t'
							<< "类别：" << read[y].substr(46, 4) << '\t'
							<< "借书日期：" << read[y].substr(51, 15) << '\t'
							<< "可借天数：" << read[y].substr(67, 4) << '\t'
							<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
							<< "还书日期：" << read[y].substr(88, 15) << endl;
				}
				break;
			}
			case 3:
			{
				int r;
				string huan;
				date jieshu;
				int y, m, d;
				cout << "请输入想要查询的还书日期：";
				cin >> y >> m >> d;
				jieshu.setdate1(y, m, d);
				huan = y + '/' + m + '/' + d;
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(86, 15, huan) == 0)
							cout << "图书编号：" << read[y].substr(14, 10)
							<< "书名：" << read[y].substr(25, 20) << '\t'
							<< "类别：" << read[y].substr(46, 4) << '\t'
							<< "借书日期：" << read[y].substr(51, 15) << '\t'
							<< "可借天数：" << read[y].substr(67, 4) << '\t'
							<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
							<< "还书日期：" << read[y].substr(88, 15) << endl;
				}
				break;
			}
			case 4:
			{
				string ming;
				int r;
				cout << "图书书名：";
				getline(cin, ming);
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(25, 20, ming) == 0)
							cout << "图书编号：" << read[y].substr(14, 10)
							<< "书名：" << read[y].substr(25, 20) << '\t'
							<< "类别：" << read[y].substr(46, 4) << '\t'
							<< "借书日期：" << read[y].substr(51, 15) << '\t'
							<< "可借天数：" << read[y].substr(67, 4) << '\t'
							<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
							<< "还书日期：" << read[y].substr(88, 15) << endl;
				}
			}
			case 5:
			{
				int r;
				string m;
				cout << "请输入书类：";
				getline(cin, m);
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(46, 4, m) == 0)
							cout << "图书编号：" << read[y].substr(14, 10)//截取图书编号
							<< "书名：" << read[y].substr(25, 20) << '\t'
							<< "类别：" << read[y].substr(46, 4) << '\t'
							<< "借书日期：" << read[y].substr(51, 15) << '\t'
							<< "可借天数：" << read[y].substr(67, 4) << '\t'
							<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
							<< "还书日期：" << read[y].substr(88, 15) << endl;
				}
			}
			default:
				break;
			}
			dateFile.close();
		}
	}
	case 2://与学生类相似
	{
		int y = 0;
		dateFile.open("teacher.txt", ios::in);
		if (dateFile.fail())
		{
			cout << "进入失败\n";
			exit(0);
		}
		while (!dateFile.eof())
		{
			char z1[15];
			while (1)
			{
				for (y = 0;;)
				{
					getline(dateFile, read[y], '\n');
					if (dateFile.fail())
					{
						cout << "借书信息读取失败！";
						break;
					}
					cout << "下面是您的借书信息：\n";
					if (read[y].compare(1, 13, z) == 0)//read[y]中1-13的字符与z字符串是否相等
					{
						cout << "图书编号：" << read[y].substr(14, 10)//截取图书编号
							<< "书名：" << read[y].substr(25, 20) << '\t'
							<< "类别：" << read[y].substr(46, 2) << '\t'
							<< "借书日期：" << read[y].substr(49, 15) << '\t'
							<< "可借天数：" << read[y].substr(65, 4) << '\t'
							<< "最晚还书日期；" << read[y].substr(70, 15) << '\t'
							<< "还书日期：" << read[y].substr(86, 15) << endl;
						y++;
					}//比较read的学号与z中的账号，相同则输出
					if (y == 0) cout << "暂无借书记录\n";
					else cout << "共" << y << "条记录";
					cout << "记录输出完毕\n";
				}
			}
		}
		system("pause");
		cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
		cout << "≈                                            ≈" << endl;
		cout << "≈请选择您先要查询类别：1.图书编号            ≈" << endl;
		cout << "≈                      2.借书日期            ≈" << endl;
		cout << "≈                      3.还书日期            ≈" << endl;
		cout << "≈                      4.书名                ≈" << endl;
		cout << "≈                      5.书类                ≈" << endl;
		cout << "≈                                            ≈" << endl;
		cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			string bian;
			int r;
			cout << "请输入图书编号：";
			getline(cin, bian);
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(14, 10, bian) == 0)
						cout << "图书编号：" << read[y].substr(14, 10)//截取图书编号
						<< "书名：" << read[y].substr(25, 20) << '\t'
						<< "类别：" << read[y].substr(46, 4) << '\t'
						<< "借书日期：" << read[y].substr(51, 15) << '\t'
						<< "可借天数：" << read[y].substr(67, 4) << '\t'
						<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
						<< "还书日期：" << read[y].substr(88, 15) << endl;
			}
			cout << "共" << r << "条记录";
			dateFile.close();
			cin.ignore();
			break;
		}
		case 2:
		{
			int r;
			string jie;
			date jieshu;
			int y, m, d;
			cout << "请输入想要查询的借书日期：";
			cin >> y >> m >> d;
			jieshu.setdate1(y, m, d);
			jie = y + '/' + m + '/' + d;
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(49, 15, jie) == 0)
						cout << "图书编号：" << read[y].substr(14, 10)
						<< "书名：" << read[y].substr(25, 20) << '\t'
						<< "类别：" << read[y].substr(46, 4) << '\t'
						<< "借书日期：" << read[y].substr(51, 15) << '\t'
						<< "可借天数：" << read[y].substr(67, 4) << '\t'
						<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
						<< "还书日期：" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		case 3:
		{
			int r;
			string huan;
			date jieshu;
			int y, m, d;
			cout << "请输入想要查询的还书日期：";
			cin >> y >> m >> d;
			jieshu.setdate1(y, m, d);
			huan = y + '/' + m + '/' + d;
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(86, 15, huan) == 0)
						cout << "图书编号：" << read[y].substr(14, 10)
						<< "书名：" << read[y].substr(25, 20) << '\t'
						<< "类别：" << read[y].substr(46, 4) << '\t'
						<< "借书日期：" << read[y].substr(51, 15) << '\t'
						<< "可借天数：" << read[y].substr(67, 4) << '\t'
						<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
						<< "还书日期：" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		case 4:
		{
			string ming;
			int r;
			cout << "图书书名：";
			getline(cin, ming);
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(25, 20, ming) == 0)
						cout << "图书编号：" << read[y].substr(14, 10)
						<< "书名：" << read[y].substr(25, 20) << '\t'
						<< "类别：" << read[y].substr(46, 4) << '\t'
						<< "借书日期：" << read[y].substr(51, 15) << '\t'
						<< "可借天数：" << read[y].substr(67, 4) << '\t'
						<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
						<< "还书日期：" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		case 5:
		{
			int r;
			string m;
			cout << "请输入书类：";
			getline(cin, m);
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(46, 4, m) == 0)
						cout << "图书编号：" << read[y].substr(14, 10)//截取图书编号
						<< "书名：" << read[y].substr(25, 20) << '\t'
						<< "类别：" << read[y].substr(46, 4) << '\t'
						<< "借书日期：" << read[y].substr(51, 15) << '\t'
						<< "可借天数：" << read[y].substr(67, 4) << '\t'
						<< "最晚还书日期；" << read[y].substr(72, 15) << '\t'
						<< "还书日期：" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		default:
			break;
		}
		dateFile.close();
		//操作（读取与账号相同的所有信息、排序）
	}
	case 3:
	{
		for (;;)
		{
			for (int f = 0; f < 100; f++)
				read[f] = "";//清空read内容
			cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n";
			cout << "≈                                            ≈\n";
			cout << "≈请选择要操作的类别：  A.学生（借书信息）    ≈\n";
			cout << "≈                      B.老师（借书信息）    ≈\n";
			cout << "≈                      C.账户操作            ≈\n";
			cout << "≈                                            ≈\n";
			cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n";
			char n;
			cin >> n;
			switch (n)
			{
			case 'A':
			{
				int dd = 0;
				string c;//输入的学号密码
				cout << "请输入学号、密码：";
				cin.ignore();
				getline(cin, c);
				c.insert(0, "S");
				/* */dateFile.open("zhanghao.txt", ios::in);
				if (dateFile.fail())
				{
					cout << "进入失败\n";
					exit(0);
				}
				dateFile.seekp(0L, ios::beg);
				while (!dateFile.eof())
				{
					getline(dateFile, read[dd], '\n');

					if (read[dd].compare(1, 20, c) == 0)
					{
						cout << "输入成功";
						break;
					}
					break;
				}
				if (dateFile.eof())
				{
					cout << "账户不存在\n请重新输入学号、密码：";
					getline(cin, c);
				}/* */           //不验证？？？？？
				dateFile.close();
				char k;
				int m;
				xinxi A(c, 13);
				cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n";
				cout << "≈                              ≈\n";
				cout << "≈请选择操作：  a.借书          ≈\n";
				cout << "≈              b.还书          ≈\n";
				cout << "≈                              ≈\n";
				cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n";
				cin >> k;
				dateFile.ignore();
				dateFile.open("student.txt", ios::out | ios::app);
				if (dateFile.fail())
				{
					cout << "文件打开失败";
					exit(0);
				}
				if (k == 'a')
				{
					cout << "借几本书：";
					cin >> m;
					for (int k = 0; k < m; k++)
					{
						A.setdate();
						if (A.getlei() == "珍贵类")
						{
							cout << "学生不能借珍贵类图书,请重输：";
							A.setdate();
						}
						writerecord(A, m);//写借书信息
					}
				}
				else
				{
					string hao;//需归还图书的图书编号
					date D;
					cout << "请输入需归还图书的图书编号：";
					getline(cin, hao);
					for (;;)
					{
						getline(dateFile, read[0]);
						string p = " ";
						string cx;//学号
						cx.assign(c, 1, 13);
						if (read[0].compare(0, 13, cx) == 0 && read[0].compare(14, 10, hao) == 0 && read[0].compare(pos(read[0], p, 7) + 1, 15, "暂未还书") == 0)
						{
							/*cout << "图书编号：" << read[0].substr(14, 10)//截取图书编号
								<< "书名：" << read[0].substr(25, 20) << '\t'
								<< "类别：" << read[0].substr(46, 4) << '\t'
								<< "借书日期：" << read[0].substr(51, 15) << '\t'
								<< "可借天数：" << read[0].substr(67, 4) << '\t'
								<< "最晚还书日期；" << read[0].substr(72, 15) << '\t'
								<< "还书日期：" << read[0].substr(88, 15) << endl;*///定位不对
						}
						int m, n, q;
						string ll;
						cout << "请输入还书日期：";
						cin >> m >> n >> q;
						D.setdate1(m, n, q);
						ll = D.gety() + '/' + D.getm() + '/' + D.getd();
						read[0].substr(88, 15) = ll;
						if (ll > read[0].substr(72, 15))
							cout << "***警告：超出限定归还日期！***";
					}
				}
				dateFile.ignore();
				break;
			}
			case 'B':
			{

			}
			case 'C':
			{
				cout << "请输入想要进行的操作：1.增加账户 2.修改账户\n";
				int f;//增加或修改账户
				cin >> f;
				if (f == 1)
				{
					string zeng, zeng1, zeng2;//zneg为身份加学号，zeng1为密码，zeng2为姓名
					cout << "增加的账户类型：1.学生 2.老师 3.管理员\n";
					int t;
					cin >> t;
					dateFile.open("zhanghao.txt", ios::in | ios::app);
					if (dateFile.fail())
					{
						cout << "文件打开失败";
						exit(0);
					}
					if (t == 1)
					{
						zeng[0] = 'S';
						cout << "请输入学号：";
						cin.ignore();
						getline(cin, zeng);
						/*while (1)
						{
							getline(dateFile, zeng1);
							if (zeng1.compare(1, 13, zeng) == 0)//未经处理的异常？？？？？
							{
								cout << "该账号已存在：请重输：";
								cin >> zeng;
								break;
							}
							else break;
						}*/
						cout << "请输入六位密码：";
						cin.ignore();
						getline(cin, zeng1);
						cout << "请输入姓名：";
						cin.ignore();
						getline(cin, zeng2);
						cout << "添加成功";
						dateFile.seekp(0L, ios::end);
						dateFile << zeng << " " << zeng1 << " " << zeng2 << endl;
						dateFile.close();
					}
					else
					{
						if (t == 2)
						{
							zeng[0] = 'T';
							cout << "请输入教师号：";
							getline(cin, zeng);
							while (1)
							{
								getline(dateFile, zeng1);
								if (zeng1.compare(1, 10, zeng) == 0)
								{
									cout << "该账号已存在：请重输：";
									cin >> zeng;
									break;
								}
								else break;
							}
							zeng[11] = ' ';
							cout << "请输入六位密码：";
							getline(cin, zeng2);
							zeng = zeng + zeng2;
							dateFile << zeng;
							dateFile << zeng << endl;
							cout << "添加成功";
							dateFile.close();
						}
						else
						{
							zeng[0] = 'M';
							cout << "请输入管理员号：";
							getline(cin, zeng);
							dateFile.close();
							while (1)
							{
								getline(dateFile, zeng1);
								if (zeng1.compare(1, 8, zeng) == 0)
								{
									cout << "该账号已存在：请重输：";
									cin >> zeng;
									break;
								}
								else break;
							}
							zeng[11] = ' ';
							cout << "请输入六位密码：";
							getline(cin, zeng2);
							zeng = zeng + zeng2;
							dateFile << zeng;
							dateFile << zeng << endl;
							cout << "添加成功";
							dateFile.close();
						}
					}
				}
				else
				{
					Zhanghao W;
					string xiu, find, change1, change2;
					int str;
					dateFile.open("zhanghao.txt", ios::in | ios::app);//修改账户
					cout << "请输入想要修改的账户号：";
					getline(cin, xiu);
					while (1)
					{
						getline(dateFile, find);
						str = xiu.size();
						if (find.compare(1, str, xiu) == 0)//未经处理的异常？？？？？？
						{

							W.jinru(find);//将账号信息输入Zhanghao W类
							cout << "该账户的详细信息为：\n"
								<< "账号：" << W.getzhanghao()
								<< "姓名：" << W.getname();
						}
					}
					W.changesecret();//修改密码
					dateFile.close();
				}
				dateFile.close();
			}
			default:
				break;
			}
		}
	default:
		break;
	}
	}
}