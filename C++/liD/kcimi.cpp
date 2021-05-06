#include <stdio.h>
#include <math.h>

double fexp(int n, int k)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += pow(i,k);
    return sum;
}

int main()
{
    int n, k;
    printf("please input n and k:\n");
    scanf("%d%d",&n,&k);
    printf("sum=%.0f\n",fexp(n,k));
    return 0;
}
