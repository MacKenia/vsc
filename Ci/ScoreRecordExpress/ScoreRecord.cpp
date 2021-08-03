#include <sc.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
struct score{
	char Cname[10];
	char Ename[5];
	int Score;
	bool operator==(const char *s)
	{
		// return !(strcmp(Ename,s));
		for(int i = 0; s[i] != '\0'; i++)
		{
			if(s[i]!=Ename[i]) return 0;
		}
		return 1;
	}
}example = {"","",0};

vector<score> scores;
vector<score>::iterator p;

void capslockt(bool f)
{
	if(GetKeyState(VK_CAPITAL) != f)
	{
		keybd_event(VK_CAPITAL,0,0,0);
 		keybd_event(VK_CAPITAL,0,KEYEVENTF_KEYUP,0);
	}
}

int getn()
{
	int r, len;
	bool f = true;
	char tmp[10];
	cin >> tmp;
	len = strlen(tmp);
	for(int i = 0; i < len; i++)
	{
		if(!(tmp[i]>='0' && tmp[i] <= '9'))
		{
			cout << "输入有误请重新输入: " ;
			r = getn();
			f = false;
			break;
		}
	}
	if(f) for(int i = 0; i < len; i++)
	{
		r += (int)(tmp[i]-'0')*pow(10,len-i-1);
	}
	return r;
}

int show(score stut)
{ 
    cout
	<< "姓名: " << stut.Cname << endl
    << "简拼: " << stut.Ename << endl
    << "成绩: " << stut.Score << endl << endl;
    return 1;
}

//显示记录
int showRecord()
{
    for_each(scores.begin(),scores.end(),show);
    return 1;
}


void FirstLetter(int nCode, char& strRet);  
void GetFirstLetter(char* strName, char* strFirstLetter, int nLen)  
{
	int ucHigh, ucLow;  
	int nCode;
	char strRet;
	memset(strFirstLetter, 0, sizeof(nLen));
	int len = 0; 
	int nameLen = (int)strlen(strName);
	for(int i=0; i < nameLen; i += 2)
	{
		ucHigh = (int)(strName[i + 0] & 0xFF);
		ucLow = (int)(strName[i + 1] & 0xFF);
		nCode = (ucHigh - 0xa0) * 100 + ucLow - 0xa0;
		// if(ucHigh < 0xa1 || ucLow < 0xa1)
		// {
		// 	continue;
		// }
		// else
		if(nCode <= 1600) continue;	
		FirstLetter(nCode, strRet);
		strFirstLetter[len] = strRet;
		len ++;  
	}
	strFirstLetter[len] = '\0';  
}  
void FirstLetter(int nCode, char& strLetter)  
{
	if(nCode >= 1601 && nCode < 1637) strLetter = 'A';
	else if(nCode >= 1637 && nCode < 1833) strLetter = 'B';
	else if(nCode >= 1833 && nCode < 2078) strLetter = 'C';
	else if(nCode >= 2078 && nCode < 2274) strLetter = 'D';
	else if(nCode >= 2274 && nCode < 2302) strLetter = 'E';
	else if(nCode >= 2302 && nCode < 2433) strLetter = 'F';
	else if(nCode >= 2433 && nCode < 2594) strLetter = 'G';
	else if(nCode >= 2594 && nCode < 2787) strLetter = 'H';
	else if(nCode >= 2787 && nCode < 3106) strLetter = 'J';
	else if(nCode >= 3106 && nCode < 3212) strLetter = 'K';
	else if(nCode >= 3212 && nCode < 3472) strLetter = 'L';
	else if(nCode >= 3472 && nCode < 3635) strLetter = 'M';
	else if(nCode >= 3635 && nCode < 3722) strLetter = 'N';
	else if(nCode >= 3722 && nCode < 3730) strLetter = 'O';
	else if(nCode >= 3730 && nCode < 3858) strLetter = 'P';
	else if(nCode >= 3858 && nCode < 4027) strLetter = 'Q';
	else if(nCode >= 4027 && nCode < 4086) strLetter = 'R';
	else if(nCode >= 4086 && nCode < 4390) strLetter = 'S';
	else if(nCode >= 4390 && nCode < 4558) strLetter = 'T';
	else if(nCode >= 4558 && nCode < 4684) strLetter = 'W';
	else if(nCode >= 4684 && nCode < 4925) strLetter = 'X';
	else if(nCode >= 4925 && nCode < 5249) strLetter = 'Y';
	else if(nCode >= 5249 && nCode < 5590) strLetter = 'Z';
	else{
		//insert code here...
		if(nCode == 7427||nCode==-116) strLetter = 'H';
		else if(nCode == 6051) strLetter = 'Y';
		else if(nCode == 7956) strLetter = 'J';
		else if(nCode == 7687) strLetter = 'Q';
		else if(nCode == 6039) strLetter = 'R';
		else if(nCode == 8529||nCode == 8646) strLetter = 'X';
	}
	
}

int main()
{
	sc m("ScoreRecordExpress");
	m.setW(55,12);
	fstream file;
	char pTemp[10], QR[5];
	char pTemp1[5];//保存汉字的首字母
	cout << "请将姓名放入name.txt保存退出" << endl
	<< "若有简拼相同者" << endl
	<<"请加一个字在其名字中加以区分" << endl
	<<"回车以继续";
	cin.get();
	file.open("name.txt",ios::in);
	while(!file.eof())
	{
		if(file.fail()) break;
		file.getline(pTemp,10,'\n');
		GetFirstLetter(pTemp,pTemp1,5);
		strcpy(example.Cname,pTemp);
		strcpy(example.Ename, pTemp1);
		// if((int)pTemp[2]==-97&&(int)pTemp[3]==-112) example.Ename[1] = 'H';
		// if((int)pTemp[4]==-103&&(int)pTemp[5]==72) example.Ename[2] = 'T';
		if(!(int)pTemp[0]) continue;
		scores.push_back(example);
	}
	file.close();
	showRecord();
	cout << "现在开始录入成绩，请以大写的方式输入简拼(输入！退出，)：" << endl;
	capslockt(true);
	while(false)
	{
		int S;
		cout << "请输入同学的简拼：";
		cin >> QR;
		for(int i = 0; i < 5; i++) if(QR[i] >= 'a') QR[i]-=32;
		if(QR[0] == '!') break;
		cin.ignore();
		p = find(scores.begin(),scores.end(),QR);
		while(strcmp(p->Ename,QR))
		{
			cout << "为找到该同学，请核对！或者重新输入：";
			cin >> QR;
			cin.ignore();
			for(int i = 0; i < 5; i++) if(QR[i] >= 'a') QR[i]-=32;
			p = find(scores.begin(),scores.end(),QR);
		}
		cout << "该同学的名字为: " << p->Cname << endl;
		cout << "请输入成绩: ";
		S = getn();
		p -> Score = S;
		file.open("score.txt",ios::out);
		for(p = scores.begin(); p != scores.end(); p++)
		{
			file << p->Score << endl;
		}
		file.close();
		
	}
	while(true)
	{
		vector<score>::iterator* pos = new vector<score>::iterator[scores.size()]; //存放候选人的容器位置
		int candidate; //候选人数量
		int cur; //选择光标的位置
	}
	showRecord();
	capslockt(false);
	return 0;
}
 
