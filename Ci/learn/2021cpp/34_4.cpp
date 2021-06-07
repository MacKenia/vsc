/**
 * 使用 char * 参数来完成把一串英文的每个单词的首字母大写
 */
#include <bits/stdc++.h>

using namespace std;

int fun2()
{
    char *p, str[80];
    cin.getline(str, 80);
    for (p = str; *p != '\0'; p++)
    {
        if(*(p-1) == ' '&& *p >= 'a' && *p <= 'z') *p -= 32;
    }
    cout << str;
    return 0;
}

int fun()
{
    char *p, q = ' ';
    while(scanf("%c", p)&&*p != '\n')
    {
        if(q == ' ' && *p <= 'z' && *p >= 'a') *p -= 32;
        q = *p;
        printf("%c",q);
    }
    return 0;
}

int main()
{
    fun2();
    return 0;
}
