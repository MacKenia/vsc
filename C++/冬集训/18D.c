#include<stdio.h>

int main()
{
    int p(int n);
    int n;
    while(scanf("%d", &n))
    {
        if (n > 18||n < 0&&(-n)%2==1) printf("Overflow!\n");
        else if (n < 7||n<0&&(-n)%2==0) printf("Underflow!\n");
        else printf("%d\n",p(n));
    }
    return 0;
}

int p(int n)
{
    if(n == 0) return 1;
    return n * p(n-1);
}
