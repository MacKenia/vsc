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
void writerecord(xinxi XX, int n)//��������Ϣд���ļ�
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
		<< "��δ����" << endl;
}
int pos(string T, string P, int n)//�ҵڼ��γ��ֵ�ĳ���ַ���λ��
{
	if (n == 0)return -1;//�൱��û��
	int count = 0;
	unsigned begined = 0;
	while ((begined = T.find(P, begined)) != string::npos) {
		count++;
		begined += P.length();
		if (n == count) {
			return begined - 1;
		}
	}
	return -2;//��ζ��û����ô���
}
int main()
{
	int i;//��ݱ��
	string d, d1;//dΪ������˻��š����룬d1Ϊ���ļ�����ȡ���˻��š�����
	string z;//zΪ������ѧ��
	string read[100];
	cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
	cout << "��                                            ��" << endl;
	cout << "����ѡ��������ݣ�1.ѧ��                      ��" << endl;
	cout << "��                2.��ʦ                      ��" << endl;
	cout << "��                3.����Ա                    ��" << endl;
	cout << "��                                            ��" << endl;
	cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
	cin >> i;
	cin.ignore();
	cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
	cout << "��                                            ��" << endl;
	cout << "��    ѧ��/��ʦ��/����Ա�ţ�                  ��" << endl;
	cout << "��                    ���룺                  ��" << endl;
	cout << "��                                            ��" << endl;
	cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
	cout << "       *�˺ź����룬�м���һ���ո�ֿ���\n";
	getline(cin, d);//�Ӽ�������ѧ�š�����
	cin.clear();
	while (1)
	{
		if (i == 1)
			d.insert(0, "S");//��d����ǰ�����S
		else
		{
			if (i == 2)
				d.insert(0, "T");//��d����ǰ�����T
			else d.insert(0, "M");//��d����ǰ�����M
		}
		dateFile.seekp(0L, ios::beg);
		cin.clear();
		dateFile.open("zhanghao.txt", ios::in);
		if (dateFile.fail())
		{
			cout << "�ļ���ʧ��";
			exit(0);
		}
		while (!dateFile.eof())
		{
			char t[255];
			dateFile.getline(t, 255); //���ļ��ж�ȡһ�����ݴ���d1��
			d1.erase();
			d1.append(t);
			if (dateFile.fail())
			{
				cout << "��ȡʧ��";
				break;
			}
			
			if (d == d1)//�ظ�������֤
			{
				cout << "��¼�ɹ���";
				if (i == 1)
					z.assign(d, 1, 13);//��d��ѧ�Ÿ�ֵ��z//ֻ�ܶ���һ�У������У�������
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
			cout << "δ��¼�ɹ�";
			cout << "�����������˺ź�����";
			cin.ignore();
			getline(cin, d);
		}
		else break;
	}
	dateFile.close();
	system("pause");  //�����������
	//��ʼ��������
	switch (i)
	{
	case 1:
	{
		cout << "��ѡ�������1.�޸����� 2.��ѯ������Ϣ��\n";
		int a;
		cin >> a;
		if (a == 1)
		{
			string yuan, gai1, gai2;
			cout << "������ԭ���룺";
			cin >> yuan;
			if (yuan.compare(15, 6, d1) == 0)
			{
				cout << "��֤�ɹ�";
				cout << "�����������룺";
				cin >> gai1;
				cout << "����һ�����������룺";
				cin >> gai2;
				if (gai1 == gai2)
				{
					d1.replace(15, 6, gai1);
					dateFile.open("zhanghao.txt", ios::in | ios::app);
					//��ԭ���ļ�¼ɾ����������
					getline(cin, d1);
					dateFile.close();
					cout << "�޸ĳɹ�";
				}
			}
			else cout << "����������������룬����ϵ����Ա";
		}
		else
		{
			int y;
			dateFile.open("student.txt", ios::in);
			if (dateFile.fail())
			{
				cout << "����ʧ��\n";
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
							cout << "������Ϣ��ȡʧ�ܣ�";
							break;
						}
						if (read[y].compare(1, 13, z) == 0)//read[y]��1-13���ַ���z�ַ����Ƿ����
							y++;
						//�Ƚ�read��ѧ����z�е��˺ţ���ͬ��y����
						if (y == 0) cout << "���޽����¼\n";
						else cout << "��" << y << "����¼";
					}
				}
			}
			cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
			cout << "��                                            ��" << endl;
			cout << "����ѡ������Ҫ��ѯ���1.ͼ����            ��" << endl;
			cout << "��                      2.��������            ��" << endl;
			cout << "��                      3.��������            ��" << endl;
			cout << "��                      4.����                ��" << endl;
			cout << "��                      5.����                ��" << endl;
			cout << "��                                            ��" << endl;
			cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
			int k;
			cin >> k;
			switch (k)
			{
			case 1:
			{
				string bian;
				int r;
				cout << "������ͼ���ţ�";
				getline(cin, bian);
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(14, 10, bian) == 0)
							cout << "ͼ���ţ�" << read[y].substr(14, 10)//��ȡͼ����
							<< "������" << read[y].substr(25, 20) << '\t'
							<< "���" << read[y].substr(46, 4) << '\t'
							<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
							<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
							<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
							<< "�������ڣ�" << read[y].substr(88, 15) << endl;
				}
				cout << "��" << r << "����¼";
				dateFile.close();
				break;
			}
			case 2:
			{
				int r;
				string jie;
				date jieshu;
				int y, m, d;
				cout << "��������Ҫ��ѯ�Ľ������ڣ�";
				cin >> y >> m >> d;
				jieshu.setdate1(y, m, d);
				jie = y + '/' + m + '/' + d;
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(49, 15, jie) == 0)
							cout << "ͼ���ţ�" << read[y].substr(14, 10)
							<< "������" << read[y].substr(25, 20) << '\t'
							<< "���" << read[y].substr(46, 4) << '\t'
							<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
							<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
							<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
							<< "�������ڣ�" << read[y].substr(88, 15) << endl;
				}
				break;
			}
			case 3:
			{
				int r;
				string huan;
				date jieshu;
				int y, m, d;
				cout << "��������Ҫ��ѯ�Ļ������ڣ�";
				cin >> y >> m >> d;
				jieshu.setdate1(y, m, d);
				huan = y + '/' + m + '/' + d;
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(86, 15, huan) == 0)
							cout << "ͼ���ţ�" << read[y].substr(14, 10)
							<< "������" << read[y].substr(25, 20) << '\t'
							<< "���" << read[y].substr(46, 4) << '\t'
							<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
							<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
							<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
							<< "�������ڣ�" << read[y].substr(88, 15) << endl;
				}
				break;
			}
			case 4:
			{
				string ming;
				int r;
				cout << "ͼ��������";
				getline(cin, ming);
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(25, 20, ming) == 0)
							cout << "ͼ���ţ�" << read[y].substr(14, 10)
							<< "������" << read[y].substr(25, 20) << '\t'
							<< "���" << read[y].substr(46, 4) << '\t'
							<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
							<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
							<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
							<< "�������ڣ�" << read[y].substr(88, 15) << endl;
				}
			}
			case 5:
			{
				int r;
				string m;
				cout << "���������ࣺ";
				getline(cin, m);
				while (1)
				{
					for (r = 0; r <= y; r++)
						if (read[y].compare(46, 4, m) == 0)
							cout << "ͼ���ţ�" << read[y].substr(14, 10)//��ȡͼ����
							<< "������" << read[y].substr(25, 20) << '\t'
							<< "���" << read[y].substr(46, 4) << '\t'
							<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
							<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
							<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
							<< "�������ڣ�" << read[y].substr(88, 15) << endl;
				}
			}
			default:
				break;
			}
			dateFile.close();
		}
	}
	case 2://��ѧ��������
	{
		int y = 0;
		dateFile.open("teacher.txt", ios::in);
		if (dateFile.fail())
		{
			cout << "����ʧ��\n";
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
						cout << "������Ϣ��ȡʧ�ܣ�";
						break;
					}
					cout << "���������Ľ�����Ϣ��\n";
					if (read[y].compare(1, 13, z) == 0)//read[y]��1-13���ַ���z�ַ����Ƿ����
					{
						cout << "ͼ���ţ�" << read[y].substr(14, 10)//��ȡͼ����
							<< "������" << read[y].substr(25, 20) << '\t'
							<< "���" << read[y].substr(46, 2) << '\t'
							<< "�������ڣ�" << read[y].substr(49, 15) << '\t'
							<< "�ɽ�������" << read[y].substr(65, 4) << '\t'
							<< "���������ڣ�" << read[y].substr(70, 15) << '\t'
							<< "�������ڣ�" << read[y].substr(86, 15) << endl;
						y++;
					}//�Ƚ�read��ѧ����z�е��˺ţ���ͬ�����
					if (y == 0) cout << "���޽����¼\n";
					else cout << "��" << y << "����¼";
					cout << "��¼������\n";
				}
			}
		}
		system("pause");
		cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
		cout << "��                                            ��" << endl;
		cout << "����ѡ������Ҫ��ѯ���1.ͼ����            ��" << endl;
		cout << "��                      2.��������            ��" << endl;
		cout << "��                      3.��������            ��" << endl;
		cout << "��                      4.����                ��" << endl;
		cout << "��                      5.����                ��" << endl;
		cout << "��                                            ��" << endl;
		cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			string bian;
			int r;
			cout << "������ͼ���ţ�";
			getline(cin, bian);
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(14, 10, bian) == 0)
						cout << "ͼ���ţ�" << read[y].substr(14, 10)//��ȡͼ����
						<< "������" << read[y].substr(25, 20) << '\t'
						<< "���" << read[y].substr(46, 4) << '\t'
						<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
						<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
						<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
						<< "�������ڣ�" << read[y].substr(88, 15) << endl;
			}
			cout << "��" << r << "����¼";
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
			cout << "��������Ҫ��ѯ�Ľ������ڣ�";
			cin >> y >> m >> d;
			jieshu.setdate1(y, m, d);
			jie = y + '/' + m + '/' + d;
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(49, 15, jie) == 0)
						cout << "ͼ���ţ�" << read[y].substr(14, 10)
						<< "������" << read[y].substr(25, 20) << '\t'
						<< "���" << read[y].substr(46, 4) << '\t'
						<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
						<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
						<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
						<< "�������ڣ�" << read[y].substr(88, 15) << endl;
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
			cout << "��������Ҫ��ѯ�Ļ������ڣ�";
			cin >> y >> m >> d;
			jieshu.setdate1(y, m, d);
			huan = y + '/' + m + '/' + d;
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(86, 15, huan) == 0)
						cout << "ͼ���ţ�" << read[y].substr(14, 10)
						<< "������" << read[y].substr(25, 20) << '\t'
						<< "���" << read[y].substr(46, 4) << '\t'
						<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
						<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
						<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
						<< "�������ڣ�" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		case 4:
		{
			string ming;
			int r;
			cout << "ͼ��������";
			getline(cin, ming);
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(25, 20, ming) == 0)
						cout << "ͼ���ţ�" << read[y].substr(14, 10)
						<< "������" << read[y].substr(25, 20) << '\t'
						<< "���" << read[y].substr(46, 4) << '\t'
						<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
						<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
						<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
						<< "�������ڣ�" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		case 5:
		{
			int r;
			string m;
			cout << "���������ࣺ";
			getline(cin, m);
			while (1)
			{
				for (r = 0; r <= y; r++)
					if (read[y].compare(46, 4, m) == 0)
						cout << "ͼ���ţ�" << read[y].substr(14, 10)//��ȡͼ����
						<< "������" << read[y].substr(25, 20) << '\t'
						<< "���" << read[y].substr(46, 4) << '\t'
						<< "�������ڣ�" << read[y].substr(51, 15) << '\t'
						<< "�ɽ�������" << read[y].substr(67, 4) << '\t'
						<< "���������ڣ�" << read[y].substr(72, 15) << '\t'
						<< "�������ڣ�" << read[y].substr(88, 15) << endl;
			}
			cin.ignore();
			break;
		}
		default:
			break;
		}
		dateFile.close();
		//��������ȡ���˺���ͬ��������Ϣ������
	}
	case 3:
	{
		for (;;)
		{
			for (int f = 0; f < 100; f++)
				read[f] = "";//���read����
			cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n";
			cout << "��                                            ��\n";
			cout << "����ѡ��Ҫ���������  A.ѧ����������Ϣ��    ��\n";
			cout << "��                      B.��ʦ��������Ϣ��    ��\n";
			cout << "��                      C.�˻�����            ��\n";
			cout << "��                                            ��\n";
			cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n";
			char n;
			cin >> n;
			switch (n)
			{
			case 'A':
			{
				int dd = 0;
				string c;//�����ѧ������
				cout << "������ѧ�š����룺";
				cin.ignore();
				getline(cin, c);
				c.insert(0, "S");
				/* */dateFile.open("zhanghao.txt", ios::in);
				if (dateFile.fail())
				{
					cout << "����ʧ��\n";
					exit(0);
				}
				dateFile.seekp(0L, ios::beg);
				while (!dateFile.eof())
				{
					getline(dateFile, read[dd], '\n');

					if (read[dd].compare(1, 20, c) == 0)
					{
						cout << "����ɹ�";
						break;
					}
					break;
				}
				if (dateFile.eof())
				{
					cout << "�˻�������\n����������ѧ�š����룺";
					getline(cin, c);
				}/* */           //����֤����������
				dateFile.close();
				char k;
				int m;
				xinxi A(c, 13);
				cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n";
				cout << "��                              ��\n";
				cout << "����ѡ�������  a.����          ��\n";
				cout << "��              b.����          ��\n";
				cout << "��                              ��\n";
				cout << "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n";
				cin >> k;
				dateFile.ignore();
				dateFile.open("student.txt", ios::out | ios::app);
				if (dateFile.fail())
				{
					cout << "�ļ���ʧ��";
					exit(0);
				}
				if (k == 'a')
				{
					cout << "�輸���飺";
					cin >> m;
					for (int k = 0; k < m; k++)
					{
						A.setdate();
						if (A.getlei() == "�����")
						{
							cout << "ѧ�����ܽ������ͼ��,�����䣺";
							A.setdate();
						}
						writerecord(A, m);//д������Ϣ
					}
				}
				else
				{
					string hao;//��黹ͼ���ͼ����
					date D;
					cout << "��������黹ͼ���ͼ���ţ�";
					getline(cin, hao);
					for (;;)
					{
						getline(dateFile, read[0]);
						string p = " ";
						string cx;//ѧ��
						cx.assign(c, 1, 13);
						if (read[0].compare(0, 13, cx) == 0 && read[0].compare(14, 10, hao) == 0 && read[0].compare(pos(read[0], p, 7) + 1, 15, "��δ����") == 0)
						{
							/*cout << "ͼ���ţ�" << read[0].substr(14, 10)//��ȡͼ����
								<< "������" << read[0].substr(25, 20) << '\t'
								<< "���" << read[0].substr(46, 4) << '\t'
								<< "�������ڣ�" << read[0].substr(51, 15) << '\t'
								<< "�ɽ�������" << read[0].substr(67, 4) << '\t'
								<< "���������ڣ�" << read[0].substr(72, 15) << '\t'
								<< "�������ڣ�" << read[0].substr(88, 15) << endl;*///��λ����
						}
						int m, n, q;
						string ll;
						cout << "�����뻹�����ڣ�";
						cin >> m >> n >> q;
						D.setdate1(m, n, q);
						ll = D.gety() + '/' + D.getm() + '/' + D.getd();
						read[0].substr(88, 15) = ll;
						if (ll > read[0].substr(72, 15))
							cout << "***���棺�����޶��黹���ڣ�***";
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
				cout << "��������Ҫ���еĲ�����1.�����˻� 2.�޸��˻�\n";
				int f;//���ӻ��޸��˻�
				cin >> f;
				if (f == 1)
				{
					string zeng, zeng1, zeng2;//znegΪ��ݼ�ѧ�ţ�zeng1Ϊ���룬zeng2Ϊ����
					cout << "���ӵ��˻����ͣ�1.ѧ�� 2.��ʦ 3.����Ա\n";
					int t;
					cin >> t;
					dateFile.open("zhanghao.txt", ios::in | ios::app);
					if (dateFile.fail())
					{
						cout << "�ļ���ʧ��";
						exit(0);
					}
					if (t == 1)
					{
						zeng[0] = 'S';
						cout << "������ѧ�ţ�";
						cin.ignore();
						getline(cin, zeng);
						/*while (1)
						{
							getline(dateFile, zeng1);
							if (zeng1.compare(1, 13, zeng) == 0)//δ��������쳣����������
							{
								cout << "���˺��Ѵ��ڣ������䣺";
								cin >> zeng;
								break;
							}
							else break;
						}*/
						cout << "��������λ���룺";
						cin.ignore();
						getline(cin, zeng1);
						cout << "������������";
						cin.ignore();
						getline(cin, zeng2);
						cout << "��ӳɹ�";
						dateFile.seekp(0L, ios::end);
						dateFile << zeng << " " << zeng1 << " " << zeng2 << endl;
						dateFile.close();
					}
					else
					{
						if (t == 2)
						{
							zeng[0] = 'T';
							cout << "�������ʦ�ţ�";
							getline(cin, zeng);
							while (1)
							{
								getline(dateFile, zeng1);
								if (zeng1.compare(1, 10, zeng) == 0)
								{
									cout << "���˺��Ѵ��ڣ������䣺";
									cin >> zeng;
									break;
								}
								else break;
							}
							zeng[11] = ' ';
							cout << "��������λ���룺";
							getline(cin, zeng2);
							zeng = zeng + zeng2;
							dateFile << zeng;
							dateFile << zeng << endl;
							cout << "��ӳɹ�";
							dateFile.close();
						}
						else
						{
							zeng[0] = 'M';
							cout << "���������Ա�ţ�";
							getline(cin, zeng);
							dateFile.close();
							while (1)
							{
								getline(dateFile, zeng1);
								if (zeng1.compare(1, 8, zeng) == 0)
								{
									cout << "���˺��Ѵ��ڣ������䣺";
									cin >> zeng;
									break;
								}
								else break;
							}
							zeng[11] = ' ';
							cout << "��������λ���룺";
							getline(cin, zeng2);
							zeng = zeng + zeng2;
							dateFile << zeng;
							dateFile << zeng << endl;
							cout << "��ӳɹ�";
							dateFile.close();
						}
					}
				}
				else
				{
					Zhanghao W;
					string xiu, find, change1, change2;
					int str;
					dateFile.open("zhanghao.txt", ios::in | ios::app);//�޸��˻�
					cout << "��������Ҫ�޸ĵ��˻��ţ�";
					getline(cin, xiu);
					while (1)
					{
						getline(dateFile, find);
						str = xiu.size();
						if (find.compare(1, str, xiu) == 0)//δ��������쳣������������
						{

							W.jinru(find);//���˺���Ϣ����Zhanghao W��
							cout << "���˻�����ϸ��ϢΪ��\n"
								<< "�˺ţ�" << W.getzhanghao()
								<< "������" << W.getname();
						}
					}
					W.changesecret();//�޸�����
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