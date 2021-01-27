#include<iostream>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
typedef pair<char,int> aPair;
typedef pair<string,int> bPair;

//搭配for_each使用
void fun(bPair t)
{
    cout << t.first << ' ' << t.second << endl;
}

int main()
{
    int n, j;
    map<char,int> rules;
    map<string, int> dict;
    char t[20], s[10], r = 'A';
    //离线计算
    bool flag1 = true, flag2 = true;
    for(int i = 0, j = 0; i < 25; i++, j++)
    {
        rules.insert(aPair(i+65, (j/3)+2));
        if(i == 15&&flag1)
        {
            i++;
            flag1 = false;
        }
    }
    //检测离线计算结果
    // for_each(rules.begin(), rules.end(), fun);
    //开始输入
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        //输入处理
        for(j = 0; t[j] != '\0'; j++)
        {
            if(j == 3)
            {
                char t1[20];
                strcpy(t1, &t[j]);
                strcpy(&t[j+1], t1);
                t[j] = '-';
            }
            else if(t[j] == '-')
            {
                strcpy(&t[j], &t[j+1]);
                j--;
            }
        }
        t[j] = '\0';
        
        //字符串处理
        for(int i = 0; t[i] != '\0'; i++)
        {
            // if(t[i] == '-') continue;
            if(t[i]>='A' && t[i]<='Z')
            {
                s[i] = rules.find(t[i])->second + 48;
            }
            else s[i] = t[i];
        }
        // cout << s <<endl;
        if(!dict.count(s)) dict.insert(bPair(s,1));
        else dict.find(s)->second++;
    }
    //再次检测
    // for_each(dict.begin(), dict.end(), fun);
    for(map<string, int>::iterator pr = dict.begin(); pr != dict.end(); pr++)
    if(pr->second>1) cout << pr->first << ' ' << pr->second << endl;
    return 0;
}
