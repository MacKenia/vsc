/**
 * 顺序表的删除操作
 */
#include <iostream>
#include "List.h"

using namespace std;

struct ls
{
    int first;
    ls *next;
};

int main()
{
    LTT<ls> tool;
    ls *list, *p, *q;
    ls head;
    // 创建结点并赋值
    list = &head;
    list->first = 0;
    list->next = NULL;
    q = list;
    for(int i = 0; i < 5; i++)
    {
        p = new ls;
        p->next = NULL;
        p->first = i+1;
        // 链接到头节点
        p = tool.addA(q, p);
        list->first++;
        q = p;
    }

    tool.delB(3, list);

    // 输出内容链表内容
    p = list;
    while(list->first--)
    {
        cout << p->next->first << " ";
        p = p->next;
    }
    cout << endl;
    tool.del(list);
    return 0;
}
