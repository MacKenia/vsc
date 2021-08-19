#include <bits/stdc++.h>

using namespace std;

int chartoin(char *s)
{
    int t;
    for(int i=0; i<4; i++)
    {
        t += (s[3-i]-'0') * pow(10,i);
    }
    // cout << t << endl;
    return t;
}

int main()
{
    fstream filein("input.txt", ios::out | ios::in | ios::app);
    fstream fileout("output.txt", ios::out);
    char id[20];
    int i = 1;
    filein.close();
    cout << "请在input.txt中输入身份证，每个独占一行" << endl
    << "最终结果会输出在output.txt中" << endl
    << "完成后回车";
    getchar();
    filein.open("input.txt",ios::in);
    if(filein.fail())
    {
        cout << "初始化失败，重启程序";
        return 0;
    }
    while(!filein.eof())
    {
        filein.getline(id,20,'\n');
        if(id[0] == '\0') continue;
        cout << "正在处理第" << i++ << "条:" << id << endl;
        // cout << id;
        if(filein.fail()) break;
        fileout << 2021-(chartoin(&id[6])) << endl;
        // cout << id;
    }
    fileout.close();
    filein.close();
    cout << "搞定" << endl;
    getchar();
    return 1;
}
