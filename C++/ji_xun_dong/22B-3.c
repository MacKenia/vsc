#include<stdio.h>

int arr[500010], temp[500010], sum = 0;

int main()
{
    int magersort(int l, int r);
    int mager(int l, int m, int r);
    int n, i;
    while (~scanf("%d", &n)&&n)
    {
        for (i=0; i<n; i++)
        {
            getchar();
            scanf("%d", &arr[i]);
        }
        magersort(0, n);
        printf("*%d\n", sum);
        sum = 0;
    }
    return 0;
}

int magersort(int l, int r)
{
    int mager(int l, int m, int r);
    if(r-l==1) return 0;
    else
    {
        int m = (l+r)/2;
        magersort(l, m);
        magersort(m, r);
        mager(l, m, r);
    }
    
    return 0;
}

int mager(int l, int m, int r)
{
    int i = l, j = m, k = l;
    while(i<m&&j<r)
    if(arr[i] > arr[j])
    {
        temp[k++] = arr[j++];
        sum += m - i;
    }
    else temp[k++] = arr[i++];
    while(i<m) temp[k++] = arr[i++];
    while(j<r) temp[k++] = arr[j++];
    for(i = l, k = l; i<r; i++) arr[i] = temp[k++];
    return 0;
}
