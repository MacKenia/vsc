[toc]

## 1. 作业任务描述

二叉排序树的查找

## 2. 作业设计思路

二叉排序树中序遍历本身有序，根据此特征在遍历是只输出大于要求的值即可

## 3. 代码实现

```c++
#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *lchild, *rchild;
};

void search_binary_sort_tree(tree *t, int tar)
{
    if(t == nullptr) return;
    else
    {
        search_binary_sort_tree(t->lchild, tar);
        if(t->data >= tar) printf("%d\t", t->data);
        search_binary_sort_tree(t->rchild, tar);
    }
}

void init(tree *(*node), int *arr, int n, int i = 1) // initial tree
{
    *node = new tree;
    (*node)->data = arr[i - 1];

    if (!(2 * i > n))
        init(&(*node)->lchild, arr, n, 2 * i);
    if (!(2 * i + 1 > n))
        init(&(*node)->rchild, arr, n, 2 * i + 1);
}

void print(tree *h) // in-order traversal
{
    if (h == nullptr)
        return;
    else
    {
        print(h->lchild);
        printf("%d\t", h->data);
        print(h->rchild);
    }
}

int main()
{
    tree *t;
    int arr[] = {45,32,50,21,34,47,51,17,22,33};
    init(&t, arr, 10);
    print(t);
    cout << endl << "按由小到大顺序排列比34大的数: ";
    search_binary_sort_tree(t, 34);
    return 0;
}
```

## 4. 输入的数据及得到的结果

查找大于34的所有节点
结果
![result](result.png)

## 5. 评估算法的复杂度

查找时遍历树,时间复杂度为：$T(n) = O(n)$

空间复杂度为：$S(n) = O(1)$
