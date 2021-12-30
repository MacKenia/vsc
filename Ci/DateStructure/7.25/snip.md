[toc]

## 1. 作业任务描述

散列表的插入和删除

## 2. 作业设计思路

设计一个合适的构造方法H, 冲突解决为链地址法

## 3. 代码实现

```c++
#include <bits/stdc++.h>

using namespace std;

struct keyNode
{
    char *s;
    keyNode *next;
};


int H(const char *tar)
{
    int tmp = pow(tar[0],2);
    return (tmp%100);
}

void InsertKey(keyNode* map[], char *s)
{
    int pos = H(s);
    if(map[pos] == nullptr)
    {
        map[pos] = new keyNode;
        map[pos]->s = new char(sizeof(s));
        strcpy(map[pos]->s,s);
        map[pos]->next = nullptr;
    }
    else
    {
        keyNode *p = map[pos];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = new keyNode;
        p = p->next;
        p->s = new char(sizeof(s));
        strcpy(p->s,s);
        p->next = nullptr;
        
    }
}

void DeleteKey(keyNode* map[], char *s)
{
    int pos = H(s);
    if(map[pos] == nullptr) return;
    if(map[pos]->next == nullptr)
    {
        delete(map[pos]);
        map[pos] = nullptr;
    }
    else
    {
        keyNode *p = map[pos], *q;
        while(strcmp(p->s,s))
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete(p);
    }
}

void print(keyNode* map[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if(map[i] == nullptr) continue;
        printf("%d: ",i);
        keyNode *p = map[i];
        while (p != nullptr)
        {
            printf("%s\t", p->s);
            p=p->next;
        }
        printf("\n");
    }
    
}

int main()
{
    keyNode* S[100];
    memset(S, 0, sizeof(S));
    char* key[] = {"ac","ab","ad"};
    InsertKey(S,key[0]);
    InsertKey(S,key[1]);
    InsertKey(S,key[2]);
    cout << "插入节点后的散列表：";
    print(S,100);
    DeleteKey(S,key[1]);
    cout << "删除节点后的散列表：";
    print(S,100);
    return 0;
}
```

## 4. 输入的数据及得到的结果

插入 `ac` `ab` `ad`, 删除 `ab`
结果
![re](result.png)

## 5. 评估算法的复杂度

查找时直接访问计算获得的下标,时间复杂度为：$T(n) = O(1)$

空间复杂度为：$S(n) = O(n)$
