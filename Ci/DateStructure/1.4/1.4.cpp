/**
 * 求两个n阶矩阵的乘法算法
 * for(i=1; i<n; i++)
 *      for(j = 1; j < n; j++)
 *      {
 *          c[i][j] = 0;
 *          for(k = 1; k < n; k++)
 *              c[i][j] = c[i][j] + a[i][k]*b[k][j];
 *      }
 */

#include <bits/stdc++.h>
#define N 10

using namespace std;

int main()
{
    int a[N][N], b[N][N], c[N][N];
    int n = N;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
	{
		a[i][j] = rand() % 100;
		b[i][j] = rand() % 100;
		//cout << "a = " << a[i][j] << " b = " << b[i][j] << endl;
	}
    cout << "fill done" << endl;
    cout << "a:" << endl;
    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
		    cout << a[i][j] << "\t";
	    }
	    cout << endl;
    }
    cout << "b:" << endl;
    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
		    cout << b[i][j] << "\t";
	    }
	    cout << endl;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            // c[i][j] = 0;
            for(int k = 0; k < n; k++)
                c[i][j] = c[i][k] + a[i][k] * b[k][j];
        }
    cout << "calculate done" << endl;
    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
		    cout << c[i][j] << "\t";
	    }
	    cout << endl;
    }
    
    return 1;
}

