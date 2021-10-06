/**
 * 顺序表的删除操作
 */
#include <iostream>
#include "List.h"

using namespace std;

struct ls
{
    int i;
    ls *next;
};

int main()
{
    LTT<ls> tool;
    ls *list, *p;
    ls f;
    list = &f;
    list->i = 7;
    p = new ls;
    p->next = NULL;
    p->i = 8;
    p = tool.addA(list, p);
    cout << p->i << endl;
    for (p = list; p->next != NULL; p = p->next)
    {
        cout << p->i << " ";
    }
    cout << endl;
    return 0;
}
