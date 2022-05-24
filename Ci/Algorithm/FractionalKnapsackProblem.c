#include <stdio.h>
#include <string.h>
#define N 7

void sort(int n, int *a, int *b)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (*(a + j) * 1.0 / *(b + j) > *(a + j + 1) * 1.0 / *(b + j + 1))
            {
                int t = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = t;

                t = *(b + j);
                *(b + j) = *(b + j + 1);
                *(b + j + 1) = t;
            }
    }
}

void Knapsack(int n, int c, int *v, int *w, float *x)
{
    sort(n, v, w);
    memset(x, 0, sizeof(int) * n);
    float m = c;
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] > m)
            break;
        x[i] = 1;
        m -= v[i];
    }
    if (i < n)
        x[i] = m * 1.0 / v[i];
}

int main()
{
    int v[N] = {35, 30, 60, 50, 40, 10, 25}; // 质量
    int p[N] = {10, 40, 30, 50, 35, 40, 30}; // 价值
    float x[N] = {0};
    int c = 150;
    Knapsack(7, c, v, p, x);

    for (int i = 0; i < N; i++)
    {
        printf("质量为%d 价值为%d 的商品 拿走 %.2f\n", v[i], p[i], x[i]);
    }

    return 0;
}
