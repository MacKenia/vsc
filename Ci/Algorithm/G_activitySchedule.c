#include <stdio.h>
#include <string.h>

#define N 10

struct activity
{
    int start;
    int end
}A[N];

void sort(int n, struct activity *a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
        
    }
    
}

void GS(int n,int *s, struct activity *a)
{
    *s = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[s[i-1]].end > a[i].start) continue;
        s[i] = i;
    }
}

int main()
{
    
    return 0;
}
