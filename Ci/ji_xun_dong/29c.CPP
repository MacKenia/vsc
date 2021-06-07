#include<bits/stdc++.h>
using namespace std;

int arr[10005] = {0};
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
    
    int t, an[10005], nn;
    bool flag;
    cin >> t;
    while(t--)
    {
        scanf("%d",nn);
        for(int i = 0; i < nn; i++) scanf("%d", arr[i]);
        for(int i = 0; i < nn; i++)
        {
            for(int j = i; j < nn; j++)
            {
                int p ;
            }
        }
    }
    return 0;
}

