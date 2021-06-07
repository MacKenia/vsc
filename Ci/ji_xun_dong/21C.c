#include<stdio.h>

int main()
{
    int judge(long long int *array , int l);
    int a, i, j, k;
    long long int arr[10000];
    scanf("%d", &a);
    for (j = 0; j < a; j++)
    {
        getchar();
        scanf("N = %d", &i);
        for(k = 0; k < i*i; k++)
        {
            scanf("%lld", &arr[k]);
        }
        if(judge(arr,i)) printf("Test #%d: Symmetric.\n", j+1);
        else printf("Test #%d: Non-symmetric.\n", j+1);
    }
    
    return 0;
}

int judge(long long int *p , int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        if(*(p+i) < 0 || *(p+l*l-1-i) < 0) return 0;
        if(!(*(p+i) == *(p+l*l-1-i))) return 0;
        if (i>l/2) return 1;
    }
}
