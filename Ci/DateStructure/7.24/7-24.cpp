#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *lchild, *rchild;
};

// tree* search_binary_sort_tree(tree *t, int tar, int flag = 0)
// {
//     tree *i = nullptr;
//     if(t == nullptr) return 0;
//     if(t->data == tar) return t;
//     if(!flag && t->lchild != nullptr) t->data > t->lchild->data ? flag = 1 : flag = 2;
//     if((i=search_binary_sort_tree(t->lchild, tar)) != nullptr)
//         return i;
//     if((i=search_binary_sort_tree(t->rchild, tar)) != nullptr)
//         return i;
//     return 0;
// }

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
    // cout << endl << search_binary_sort_tree(t,5)->data << endl;
    search_binary_sort_tree(t, 34);
    return 0;
}
