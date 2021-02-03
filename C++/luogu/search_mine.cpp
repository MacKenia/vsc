#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    char chess[100][100];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> chess[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(chess[i][j] == '?')
            {
                chess[i][j] = '0';
                if(chess[i][j+1] == '*'&& j!=m-1) chess[i][j]++;
                if(chess[i+1][j] == '*'&& i!=n-1) chess[i][j]++;
                if(chess[i-1][j] == '*'&& i!=0) chess[i][j]++;
                if(chess[i][j-1] == '*'&& j!=0) chess[i][j]++;
                if(chess[i+1][j-1] == '*'&& i!=n-1&&j!=0) chess[i][j]++;
                if(chess[i-1][j+1] == '*'&& j!=m-1&&i!=0) chess[i][j]++;
                if(chess[i+1][j+1] == '*'&& j!=m-1&&i!=n-1) chess[i][j]++;
                if(chess[i-1][j-1] == '*'&& i!=0&& j!=0) chess[i][j]++;
            }
        }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%c", chess[i][j]);
        }
        printf("\n");
    }
    return 0;
}
