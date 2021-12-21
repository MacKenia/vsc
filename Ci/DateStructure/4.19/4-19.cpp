#include <bits/stdc++.h>
#define N 10
using namespace std;

struct tree{
    int data;
    tree *left;
    tree *right;
};

void print(tree *h) //preorder
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

void init(tree *(*node), int *arr, int n, int i = 1) // initial tree
{
    *node = new tree;
    (*node)->data = arr[i-1];

    if(!(2*i > n))
        init(&(*node)->left, arr, n, 2*i);
    if(!(2*i+1 > n))
        init(&(*node)->right, arr, n, 2*i+1);
}

void width(tree *p, int a[], int k = 0) // measure the width of the tree
{
    if(p == nullptr) return;
    else
    {
        a[k]++;
        width(p->left, a, k+1);
        width(p->right, a, k+1);
    }
}

int main()
{
    tree *h;
    int len =(int)(log(N)/log(2));
    int arr[N], count[len];
    int flag = 0;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i < N; i++)
    {
        arr[i] = rand() % 10;
    }
    init(&h, arr, N);
    print(h);
    width(h, count);
    for(int i=0; i < len; i++)
    {
        if(count[flag] < count[i]) flag = i;
    }
    cout << endl << count[flag] << endl;
    return 1;
}
