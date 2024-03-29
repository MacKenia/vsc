#include <stdio.h>
#include <stdlib.h>

void QuickSort(int *p, int start, int end)
{
    if(start >= end - 1) return;
    int i = start, j = end - 1;
    while (i < j)
    {
        while (p[i] <= p[start] && i < j)
        {
            i++;
        }
        while (p[j] > p[start] && i < j)
        {
            j--;
        }
        if(p[i] > p[j])
        {
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
        }
    }
    if(p[i] < p[start])
    {
        int t = p[start];
        p[start] = p[i];
        p[i] = t;
    }
    QuickSort(p, start, i);
    QuickSort(p, i, end);
}

void QuickSortS(int *p, int beg, int end, int tar)
{
    if (beg >= end)
        return;
    int i = tar, j = end;
    while (i < j)
    {
        while (p[i] <= p[beg] && i < j)
        {
            i++;
        }
        while (p[j] > p[beg] && i < j)
        {
            j--;
        }
        if (p[i] > p[j])
        {
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
        }
    }
    if (p[i] < p[beg])
    {
        int t = p[beg];
        p[beg] = p[i];
        p[i] = t;
    }
    QuickSort(p, beg, i - 1);
}

int midN(int *p, int beg, int end)
{
    if ((end - beg) % 2)
    {
        if (p[(beg + end) / 2] > p[(beg + end) / 2 + 1])
            return p[(beg + end) / 2];
        else
            return p[(beg + end) / 2 + 1];
    }
    else
        return p[(end + beg) / 2];
}

int liner_select(int *p, int n, int nth)
{
    // divide the array by five
    int group = !(n % 5) ? n / 5 : n / 5 + 1;
    int *mid = (int *)malloc(group + 1);

    // find the mid number
    for (int i = 0; i < group; i++)
    {
        QuickSort(p, 5 * i, 5 * (i + 1));
        mid[i] = midN(p, 5 * i, 5 * (i + 1) - 1);
    }

    // sort the mid array
    QuickSort(mid, 0, group);

    // get the mid number
    mid[group] = midN(mid, 0, group);

    // sort half array
    QuickSortS(p, 0, n - 1, mid[group]);
    // find the nth number

    for (int i = 0; i < group + 1; i++)
    {
        printf("%d, ", mid[i]);
    }
}

int main()
{
    int tar;
    int a[] = {29, 28, 27, 26, 25,
                 24, 23, 22, 21, 20,
                 19, 18, 17, 16, 15,
                 14, 13, 12, 11, 10,
                 9, 8, 7, 6, 5,
                 4, 3, 2};
    scanf("%d", &tar);
    liner_select(a, 10, tar);
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", a[i]);
    }
    return 0;
}
