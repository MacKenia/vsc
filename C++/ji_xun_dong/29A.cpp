#include<iostream>
#include<cmath>
using namespace std;

int arr[1000005] = {0};
void calculate(int n)
{
    for (int i = 2; i <= sqrt((double) n);i++)
    {
        if(arr[i] == 1) continue;
        for(int j = i;i*j<=n;j++) arr[i*j] = 1;
    }
}

int main()
{
    int n, f;
    calculate(1000005);
     while(~scanf("%d", &n)&&n){
         if(n>1000000)
         {
             printf("Goldbach's conjecture is wrong.\n");
             continue;
         }
         f = 1;
         for(int i = 3; i <= n/2; i++)
            if(arr[n-i] == 0&&arr[i] == 0)
            {
                printf("%d = %d + %d\n", n, i, n-i);
                f = 0;
                break;
            }
         if(f==1) printf("Goldbach's conjecture is wrong.\n");
     }
    return 0;
}
