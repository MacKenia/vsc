/**
 * 一元多项式的运算
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct Polynomial{
    int coefficient;
    int index;
};

int main()
{
    Polynomial a[10];
    Polynomial b[5] = {{2,3},{1,4},{3,1},{4,5}};
    Polynomial c[5] = {{1,4},{2,5},{3,3}};
    int m1 = 0, m2 = 0;
    for (int i = 0; i < 5; i++)
    {
        if(b[m1].index > b[i].index) m1 = i;
        if(c[m2].index > c[i].index) m2 = i;
    }
    for(int i = 0; i < 10; i++)
    {
        if(b[m1].index < c[m2].index)
        {
            a[i].index =  b[m1].index;
        }
        else
        {
            a[i].index = c[m2].index;
        }
        if(b[m1].index == c[m2].index)
        {
            a[i].coefficient = b[m1].coefficient + c[m2].coefficient;
        }
        for(int i = 0; i < 5; i++)
        {
            if(a[i].index ) ;
        }
        
    }
    return 0;
}
