#include<stdio.h>

int main()
{
    float p(int n);
    int n;
    while(scanf("%d", &n) == 1)
    {
        if (n > 18||n < 0&&(-n)%2==1) printf("Overflow!\n");
        else if (n < 7||n<0&&(-n)%2==0) printf("Underflow!\n");
        else printf("%.0f\n",p(n));
    }
    return 0;
}

float p(int n)
{
    if(n == 0) return 1;
    return n * p(n-1);
}
