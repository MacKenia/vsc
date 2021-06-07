#include <stdio.h>

int arr[1000], temp[1000], sum = 0;

int main()
{
    int magersort(int l, int r);
    int mager(int l, int m, int r);
    int n, n2, i, j = 0;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &n2);
        for(j = 0;j < n2;j++)
        {
            scanf("%d", &arr[j]);
        }
        magersort(0, j);
        printf("Scenario #%d:\n%d\n\n", i+1, sum);
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


