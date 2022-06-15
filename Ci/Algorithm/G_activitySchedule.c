#include <stdio.h>
#include <string.h>

#define N 10

struct activity
{
    int start;
    int end;
}A[N];

void sort(struct activity *a, int s, int e)
{
    if (s <= e + 1)
    {
        if(a[s].start > a[e].start)
        {
            struct activity t = a[s];
            a[s] = a[e];
            a[e] = t;
        }
        return;
    }
    
    int base = s, low = s + 1;
    for (int i = s; i < e; i++)
    {
        if (a[base].start < a[i].start)
        {
            struct activity t = a[low];
            a[low] = a[i];
            a[i] = a[low++];
        }
    }
    {
        struct activity t = a[low];
        a[low++] = a[base];
        a[base] = t;
    }
    sort(a, s, low-1);
    sort(a, low, e);
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
    sort(A, 0, N);
    return 0;
}
