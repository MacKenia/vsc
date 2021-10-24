/**
 * 回文数
 */
#include <bits/stdc++.h>
#include "List.h"

using namespace std;

struct LStrack
{
    int data;
    LStrack *next;
}tmp;

int main()
{
    LStrack *ls = NULL, *t = NULL;
    LTT<LStrack> tool;
    char st[80];
    int len = 0, i = 0;
    cout << "请输入一串字符：";
    cin >> st;
    for(int i = 0; st[i] != '\0'; i++) len++;
    tmp.data = st[0];
    tmp.next = NULL;
    ls = &tmp;
    for(i = 1; i < len/2; i++)
    {
        t = new LStrack;
        t->data = st[i];
        t->next = NULL;
        ls = tool.push(t, ls);
    }
    if(len%2) i = len/2 + 1;
    for( ; i < len; i++)
    {
        if(ls->data != st[i]) break;
        if(i != len-1) ls = tool.pop(ls);
    }
    if(i < len)
    {
        cout << st << "不是回文！" << endl;
        tool.del(ls);
    }
    else
        cout << st << "是回文！" << endl;
    return 1;
}
