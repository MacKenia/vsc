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
    LStrack *ls = NULL;
    LTT<LStrack> tool;
    char st[80];
    int len = 0;
    cout << "请输入一串字符：";
    cin >> st;
    for(int i = 0; st[i] != '\0'; i++) len++;
    tmp.data = st[0];
    tmp.next = NULL;
    ls = &tmp;
    for(int i = 1; i < len/2; i++)
    {
        tmp.data = st[i];
        tmp.next = NULL;
        tool.push(&tmp, ls);
    }
    if(!len%2) len++;
    for(int i = len/2; i < len; i++)
    {
        
    }
    return 1;
}
