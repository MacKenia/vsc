#include <bits/stdc++.h>
#include "List.h"
#define N 10

using namespace std;

struct tree 
{
    int data;
    tree *left;
    tree *right;
};

int count(tree *h)
{
    if(h->left == NULL && h->right == NULL)
    {
        return 1;
    }
    else
    {
        return count(h->left) + count(h->right);
    }
}

int main()
{
    tree *head, *p, *q;
    for(int i = 0; i < N; i++)
    {
        
    }
    return 0;
}
