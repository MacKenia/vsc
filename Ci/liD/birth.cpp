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
    fstream filein("input.txt", ios::in | ios::out | ios::app);
    fstream fileout("output.txt", ios::out);
    char id[13];
    int i = 1;
    cout << "请在input.txt中输入身份证，每个独占一行" << endl
    << "最终结果会输出在output.txt中" << endl
    << "完成后回车";
    getchar();
    while(!filein.eof())
    {
        cout << "\r" << "正在处理第" << i << "条" << endl;
        filein.getline(id,13,'\n');
        if(filein.fail())
        {
            cout << "初始化文件失败";
            break;
        }
        fileout << 2021-(chartoin(&id[6]));
        // cout << id;
    }
    fileout.close();
    filein.close();
    cout << "搞定" << endl;
    getchar();
    return 0;
}
