#include<iostream>
using namespace std;

int main()
{
    int n, t, answer[25] = {0}, d[25][25] = {0}, event[25] = {0};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        event[t-1] = i+1;
    }
    while(~scanf("%d",&t))
    {
        answer[t-1]=1;
        for(int i = 1; i < n; i++)
        {
            cin >> t;
            answer[t-1] = i+1;
        }
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(answer[i-1]==event[j-1])
                    d[i][j]=d[i-1][j-1]+1;
                else
                   d[i][j]=max(d[i-1][j],d[i][j-1]);
          }
        }
        printf("%d\n", d[n][n]);
    }
    return 0;
}
