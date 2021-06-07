#include <bits/stdc++.h>
using namespace std;

int sheep[100000000][2];

void dps()
{
    
    for (int i = 0; i < 100000000; i++)
        for (int j = 0; j < 2; j++)
        {
            if(i == 0)  sheep[i][j] = 1;
            else if(j == 0) sheep[i][j] = i + 2;
            else sheep[i][j] = sheep[sheep[i-1][j]][j-1];
        }
    sheep[1][0] = 2;
}

int main()
{
    int n, m, nn;
    dps();
    scanf("%d", &nn);
    while(nn--)
    {
    	cin >> n >> m;
    	cout << sheep[n][m] << endl;
	}

    return 0;
}

