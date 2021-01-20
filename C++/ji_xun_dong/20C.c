#include<stdio.h>

int main()
{
    int a[1000], i;
    scanf("%d", &a[0]);
    while (a[0])
    {
        scanf("%d", &a[i++]);
    }
    
    return 0;
}

int exgcd(int a, int b, int x, int y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int t = exgcd(b, a%b, x, y);
    int x0 = x, y0 = y;
    x = y0;
    y= x0 - (a / b) * y0;
    return t;
}
