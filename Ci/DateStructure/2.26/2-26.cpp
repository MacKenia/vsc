#include <bits/stdc++.h>
#include "List.h"

using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    LTT<Node> tool;
    Node* a, *b, *c, *p;
    a = new Node;
    a->data = 10;
    a->next = nullptr;
    b = new Node;
    c = new Node;
    b->data = 0;
    c->data = 0;
    for (int i = 0; i < 10; i++)
    {
        p = new Node;
        p->data = i-6;
        p->next = nullptr;
        tool.addA(a,p);
    }
    cout << "链表A的长度为: "<< a->data <<" 包含的值: ";
    tool.print(a->next);
    for (Node *m = b, *n = c, *p=a->next, *q = p->next; q;p = q, q = q->next)
    {
        if(p->data > 0)
        {
            tool.addA(m, p);
            m = m->next;
            b->data++;
        }
        else
        {
            tool.addA(n, p);
            n = n->next;
            c->data++;
        }
    }
    cout << "链表B的长度为"<<b->data<<" 包含的值: ";
    tool.print(b->next);
    cout << "链表C的长度为"<<c->data<<" 包含的值: ";
    tool.print(c->next);
    return 0;
}
