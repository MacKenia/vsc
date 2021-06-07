#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> cha[26];

int main()
{
    string str = "啊这";
	char pTemp;
	char pTemp1;
    cout << "请输入无法识别的文字: ";
    cin >> str;
	for(int i = 0; i < str.size(); i+=2)
	{
		char tmp[3] = {str[i],str[i+1],'\0'};
		cout << "请输入\"" << tmp <<"\"的首拼: ";
		cin >> pTemp1;
		pTemp1 = toupper(pTemp1);
		cha[pTemp1-'A'].push_back(((str[i] & 0xFF) - 0xa0) * 100 + ((str[i+1] & 0xFF) - 0xa0));
		cin.ignore();
	}
	cout << "请复制一下代码：" << endl << endl;
    for(int i = 0; i < 26; i++)
	{
		if(cha[i].size())
		{
			if(i) cout << "else ";
			cout << "if(";
			for(vector<int>::iterator p = cha[i].begin(); p != cha[i].end(); p++)
			{
				if(!(p == cha[i].begin())) cout << " || ";
				cout << "nCode == " << *p ;
			}
			cout << ") strLetter = '" << (char)(i+'A') << "'" << endl;
		}
	}
    getchar();
	return 0;
}
 
