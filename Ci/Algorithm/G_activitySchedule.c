#include <stdio.h>
#include <string.h>

#define N 10

struct activity
{
    int start;
    int end;
} A[N] = {{1, 4},
          {3, 5},
          {0, 6},
          {5, 7},
          {3, 8},
          {5, 9},
          {6, 10},
          {8, 11},
          {8, 12},
          {2, 13}};

void sort(struct activity a[], int s, int e)
{
    if (s >= e - 1)
        return;
    int low = s, high = e - 1;
    while (low < high)
    {
        while (a[low].start < a[s].start && low < high)
            low++;
        while (a[high].start > a[s].start && low < high)
            high--;
        if (a[low].start > a[high].start)
        {
            struct activity t = a[low];
            a[low] = a[high];
            a[high] = t;
        }
    }
    {
        struct activity t = a[low];
        a[low++] = a[s];
        a[s] = t;
    }
    sort(a, s, low);
    sort(a, low, e);
}

void GS(int n, int *s, struct activity *a)
{
    *s = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[s[i - 1]].end > a[i].start)
            continue;
        s[i] = i;
    }
}

int main()
{
    sort(A, 0, N);
    for (int i = 0; i < N; i++)
        printf("{%d,%d}\n", A[i].start, A[i].end);

    return 0;
}
