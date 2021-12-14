#include <bits/stdc++.h>
#define N 10

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

void print(tree *h)
{
    if(h == NULL)
        return;
    else
    {
        printf("%d\t",h->data);
        print(h->left);
        print(h->right);
    }
}

void exchange(tree *(*a), tree *(*b)=NULL)
{
    if(*a == NULL && *b == NULL) return;
    if(*a) exchange(&((*a)->left), &((*a)->right));
    if(b && *b) exchange(&((*b)->left), &((*b)->right));
    else return;
    tree *c;
    c = (*a)->left;
    (*a)->left = (*b)->right;
    (*b)->right = c;
}

void init(tree *(*node), int *arr, int n, int i = 1)
{
    *node = new tree;
    (*node)->data = arr[i-1];

    if(!(2*i > n))
        init(&(*node)->left, arr, n, 2*i);
    if(!(2*i+1 > n))
        init(&(*node)->right, arr, n, 2*i+1);
}

int main()
{
    int a[N];
    tree *head;
    for(int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    init(&head, a, N);
    print(head);
    exchange(&head);
    cout << endl;
    print(head);
    cout << endl;
    return 0;
}
