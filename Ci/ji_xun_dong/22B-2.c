#include<stdio.h>

int arr[5000000];

int main()
{
    int givenum(int a[], int len);
    int t, i, j;
    while(~scanf("%d", &i)&&i!=0)
    {
        for(j = 0; j < i; j++)
        {
            getchar();
            scanf("%d", &t);
            arr[j] = t;
        }
        printf("%d\n", givenum(&arr[0], i));

    }
    return 0;
}

int givenum(int a[], int len)
{
    int sum = 0, i, j;
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len - 1 - i; j++)
        {
            if(a[j]>a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                sum++;
            }
        }
    }
    return sum;
}