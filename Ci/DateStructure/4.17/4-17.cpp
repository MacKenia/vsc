#include <bits/stdc++.h>
#define N 10

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

void init(tree *(*node), int *arr, int n, int i = 1)
{
    *node = new tree;
    (*node)->data = arr[i-1];

    if(!(2*i > n))
        init(&(*node)->left, arr, n, 2*i);
    if(!(2*i+1 > n))
        init(&(*node)->right, arr, n, 2*i+1);
}

int compare(tree *a, tree *b)
{
    if(a==NULL && b!=NULL) return 0;
    if(a!=NULL && b==NULL) return 0;
    if(a->data != b->data) return 0;
    if(compare(a->left, b->left) && compare(a->right, b->right)) return 1;
    else return 0;
}

int main()
{
    
    return 0;
}
