#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *lchild;
    tree *rchild;
};

// Heap judge
// int is_binary_sort_tree(tree *p, int flag = 0)
// {
//     int i = 0;
//     if (p->lchild == nullptr && p->rchild == nullptr)
//         return flag;
//     switch (flag)
//     {
//     case 1:
//         if (p->lchild && p->data < p->lchild->data)
//         {
//             if ((i = is_binary_sort_tree(p->lchild, flag)) != 0);
//             else return 0;
//         }
//         if (p->rchild && p->data < p->rchild->data)
//         {
//             if ((i = is_binary_sort_tree(p->rchild, flag)) != 0) flag = 0;
//             else return 0;
//         }
//         return i;
//         break;
//     case 2:
//         if (p->lchild && p->data > p->lchild->data)
//         {
//             if ((i = is_binary_sort_tree(p->lchild, flag)) != 0);
//             else return 0;
//         }
//         if (p->rchild && p->data > p->rchild->data)
//         {
//             if ((i = is_binary_sort_tree(p->rchild, flag)) != 0);
//             else return 0;
//         }
//         return i;
//         break;
//     default:
//         if (p->lchild && p->rchild)
//         {
//             if (p->data < p->lchild->data && p->data < p->rchild->data)
//                 flag = 1;
//             else if (p->data > p->lchild->data && p->data > p->rchild->data)
//                 flag = 2;
//             if (flag)
//                 return is_binary_sort_tree(p, flag);
//         }
//         else if (p->rchild)
//         {
//             if (p->data < p->rchild->data)
//                 flag = 1;
//             else flag = 2;
//             if(flag)
//                 return is_binary_sort_tree(p, flag);
//         }
//         else if (p->lchild)
//         {
//             if (p->data > p->lchild->data)
//                 flag = 2;
//             else flag = 1;
//             if(flag)
//                 return is_binary_sort_tree(p, flag);
//         }
//         break;
//     }
//     return 0;
// }

int is_binary_sort_tree(tree *t)
{
    if(t->lchild == nullptr && t->rchild == nullptr) return 1;
    if(t->lchild != nullptr && t->lchild->data < t->data) return is_binary_sort_tree(t->lchild);
    else return 0;
    if(t->lchild != nullptr && t->rchild->data > t->data) return is_binary_sort_tree(t->rchild);
    else return 0;
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

void print(tree *h) // preorder
{
    if (h == nullptr)
        return;
    else
    {
        printf("%d\t", h->data);
        print(h->lchild);
        print(h->rchild);
    }
}

int main()
{
    tree *t, *tt;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ar[] = {45,12,53};
    init(&t, ar, 3);
    init(&tt, arr, 10);
    cout << "ar:";
    print(t);
    if (is_binary_sort_tree(t))
        cout << "Is binary sort tree" << endl;
    else 
        cout << "Not binary sort tree" << endl;
    cout << "arr:";
    print(tt);
    if (is_binary_sort_tree(tt))
        cout << "Is binary sort tree" << endl;
    else 
        cout << "Not binary sort tree" << endl;
    return 0;
}
