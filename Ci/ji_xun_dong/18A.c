#include<stdio.h>

int main()
{
    int sum(int a, int b);
    int i;
    for (i = 2992; i < 10000; i++)
    {
         if (sum(10, i)==sum(12, i)&&sum(10, i)==sum(16, i))
         {
            printf("%d", i);
            printf("\n");
         }
         
    }
    return 0;
}

int sum(int a, int b)
{
    int sum = 0;
    for(; b > 0;b/=a)
    {
        sum += b % a;
    }
    return sum;
}
