#include <bits/stdc++.h>

using namespace std;

int main()
{
    char f[80];
    cout << "请输入打开的文件名: ";
    cin >> f;
    ifstream file(f);
    int count = 0;
    while (!file.eof())
    {
        char line[81];
        file.getline(line, 80, '\n');
        cout << line << endl;
        if(count++ == 9) break;
    }
    if(count < 10) cout << "全部显示完毕";
    file.close();
    return 0;
}
