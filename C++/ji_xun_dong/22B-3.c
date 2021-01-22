#include<stdio.h>

int arr[500000], temp[500000];

int main()
{
    int n, i, t;
    while (~scanf("%d", &n)&&n)
    {
        for (i=0; i<n; i++)
        {
            scanf("%d", &t);
            arr[i] = t;
        }
        magersort(0, n);
    }
    return 0;
}

int magersort(int s, int t)
{
    if(s == t) return 0;
    else
    {
        int m = (s+t)/2;
        magersort(s, m);
        magersort(m + 1, t);
        mager(s, m, t);
    }
    
    return 0;
}

int mager(int s, int t)
{
    
    return 0;
}
