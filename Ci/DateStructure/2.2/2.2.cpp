/**
 * 稀疏多项式的运算
 */

#include <bits/stdc++.h>
#define N 5

using namespace std;

struct Polynomial
{
    int coefficient;
    int exponential;
};

int main()
{
    Polynomial a[2 * N];
    Polynomial b[N] = {{2, 1}, {1, 4}, {3, 7}, {4, 8}};
    Polynomial c[N] = {{1, 4}, {2, 5}, {3, 6}};
    int i = 0, j = 0, k = 0;
    while (b[i].exponential != 0 || c[j].exponential != 0)
    {
        if (b[i].exponential == c[j].exponential)
        {
            a[k].exponential = b[i].exponential;
            a[k++].coefficient = b[i++].coefficient + c[j++].coefficient;
        }
        else if (b[i].exponential < c[j].exponential)
        {
            if(b[i].exponential == 0)
            {
                a[k].exponential = c[j].exponential;
                a[k++].coefficient = c[j++].coefficient;
            }
            else
            {
                a[k].exponential = b[i].exponential;
                a[k++].coefficient = b[i++].coefficient;    
            }
        }
        else
        {
            if(c[j].exponential == 0)
            {
                a[k].exponential = b[i].exponential;
                a[k++].coefficient = b[i++].coefficient;
            }
            else
            {
                a[k].exponential = c[j].exponential;
                a[k++].coefficient = c[j++].coefficient;
            }
        }
    }
    for(int i = 0; i < k; i++)
    {
        cout << a[i].coefficient << "," << a[i].exponential << endl;
    }
    return 0;
}
