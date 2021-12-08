#include <bits/stdc++.h>
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
    if(h == NULL)
        return 0;
    else
        return count(h->left) + count(h->right) + 1;
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
    tree *head;
    int arr[N];
    for(int i = 0; i < N; i++)
        arr[i] = rand() % N;

    init(&head, arr, N);
    cout << "This tree has " << count(head) << " elements." << endl;
    return 0;
}
