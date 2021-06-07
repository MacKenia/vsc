#include <bits/stdc++.h>

using namespace std;

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
		if(ucHigh < 0xa1 || ucLow < 0xa1)
		{
			continue;
		}
		else
		{
			nCode = (ucHigh - 0xa0) * 100 + ucLow - 0xa0;
		}
		cout << nCode << endl;
		FirstLetter(nCode, strRet);
		strFirstLetter[len] = strRet;
		len ++;  
	}
	strFirstLetter[len] = '\0';  
}  
void FirstLetter(int nCode, char& strLetter)  
{  
	if(nCode >= 1601 && nCode < 1637) strLetter = 'A';
	if(nCode >= 1637 && nCode < 1833) strLetter = 'B';
	if(nCode >= 1833 && nCode < 2078) strLetter = 'C';
	if(nCode >= 2078 && nCode < 2274) strLetter = 'D';
	if(nCode >= 2274 && nCode < 2302) strLetter = 'E';
	if(nCode >= 2302 && nCode < 2433) strLetter = 'F';
	if(nCode >= 2433 && nCode < 2594) strLetter = 'G';
	if(nCode >= 2594 && nCode < 2787) strLetter = 'H';
	if(nCode >= 2787 && nCode < 3106) strLetter = 'J';
	if(nCode >= 3106 && nCode < 3212) strLetter = 'K';
	if(nCode >= 3212 && nCode < 3472) strLetter = 'L';
	if(nCode >= 3472 && nCode < 3635) strLetter = 'M';
	if(nCode >= 3635 && nCode < 3722) strLetter = 'N';
	if(nCode >= 3722 && nCode < 3730) strLetter = 'O';
	if(nCode >= 3730 && nCode < 3858) strLetter = 'P';
	if(nCode >= 3858 && nCode < 4027) strLetter = 'Q';
	if(nCode >= 4027 && nCode < 4086) strLetter = 'R';
	if(nCode >= 4086 && nCode < 4390) strLetter = 'S';
	if(nCode >= 4390 && nCode < 4558) strLetter = 'T';
	if(nCode >= 4558 && nCode < 4684) strLetter = 'W';
	if(nCode >= 4684 && nCode < 4925) strLetter = 'X';
	if(nCode >= 4925 && nCode < 5249) strLetter = 'Y';
	if(nCode >= 5249 && nCode < 5590) strLetter = 'Z';
}

int main()
{
	char pTemp[] = "橦";
	int nameLen = (int)strlen(pTemp);
	char pTemp1[128];//保存汉字的首字母
	cout << ((int)pTemp[0]) << " " << ((int)pTemp[1]) <<endl;
	GetFirstLetter(pTemp,pTemp1,128);
	cout << pTemp1 << endl;
	getchar();
	return 0;
}
 
