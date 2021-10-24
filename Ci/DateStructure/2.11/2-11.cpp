#include <bits/stdc++.h>
#include "List.h"
#define N 10

using namespace std;

struct List {
    int data;
    List *next;
};

int getMax(List *list)
{
    if(list->next == NULL) return list->data;
    else return (list->data > getMax(list->next) ? list->data : getMax(list->next));
}

int getTot(List *list)
{
    if(list->next == NULL) return 0;
    else return (1+getTot(list->next));
}

int getSum(List *list)
{
    if(list->next == NULL) return list->data;
    else return (list->data + getSum(list->next));
}

int getAve(List *list)
{
    return getSum(list)/getTot(list);
}

int main()
{
    LTT<List> tool;
    List *head = new List();
    List *p = NULL;
    head->next = NULL;
    for (int i = 0; i < N; i++)
    {
        p = new List();
        p->data = rand() % 100;
        p->next = NULL;
        p = tool.addA(head, p);
    }
    p = head->next;
    for(int i = 0; i < N; i++, p = p->next)
    {
        cout << p->data << "\t";
    }
    cout << endl;
    cout << "Max: " << getMax(head) << endl;
    cout << "Total: " << getTot(head) << endl;
    cout << "Average: " << getAve(head) << endl;
    return 0;
}
