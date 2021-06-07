/**
 * 检测口令是否满足：
 * 口令至少由6个字符构成
 * 口令中至少包含一个大写字母
 * 口令中至少包含一个小写字母
 * 口令中至少包含一个数字
 * 并指出错误
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char key[80];
    int tmp[3] = {0}, i;
    cout << "请输入口令：";
    cin >> key;
    for(i = 0; key[i] != '\0'; i++)
    {
        if(key[i]>='a'&&key[i]<='z') tmp[0]++;
        if(key[i]>='A'&&key[i]<='Z') tmp[1]++;
        if(key[i]>='0'&&key[i]<='9') tmp[2]++;
    }
    if(i>=6&&tmp[0]&&tmp[1]&&tmp[2]) cout << "口令满足要求" << endl;
    else
    {
        if(i<6) cout << "口令至少由6个字符构成" << endl;
        if(!tmp[0]) cout << "口令中至少包含一个大写字母" << endl;
        if(!tmp[1]) cout << "口令中至少包含一个小写字母" << endl;
        if(!tmp[2]) cout << "口令中至少包含一个数字" << endl;
    }
    return 0;
}
