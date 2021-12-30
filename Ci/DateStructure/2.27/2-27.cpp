#include <bits/stdc++.h>
#include "List.h"
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int Biggest(Node *p)
{
    int big = p->data;
    while (p)
    {
        if(p->data > big) big = p->data;
        p = p->next;
    }
    return big;
}

int main()
{
    int a, n;
    Node *list, *p;
    LTT<Node> tool;
    list = new Node;
    list->next = nullptr;
    p = list;
    cout << "输入链表的长度: ";
    cin >> n;
    list->data = n;
    while (n--)
    {
        cin >> a;
        Node *q = new Node;
        q->data = a;
        q->next = nullptr;
        tool.addA(p,q);
        p = p->next;
    }
    cout <<"当前链表中最大的值为: "<< Biggest(list) << endl;
    return 0;
}
