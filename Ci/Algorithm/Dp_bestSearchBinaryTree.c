#include <stdio.h>
#include <string.h>

#define N 10

int w[N * N], m[N * N], s[N * N];

void Dp_BestSearchBinaryTree(int n, double *a, double *b, double *w, double *m, int *s)
{
    memset(w, 0, sizeof(int) * n * n);
    memset(m, 0, sizeof(int) * n * n);
    memset(s, 0, sizeof(int) * n * n);
    // 初始化表格
    for (int i = 0; i < n; i++)
    {
        w[i * n + i] = a[i];
    }
    // 填表
    for (int i = 1; i < n; i++)
    {
        for (int j = 0, k = i; j < n; j++, k++)
        {
            w[j * n + k] = w[j * n + k - 1] + a[k] + b[k];
            m[j * n + k] = m[j * n + k - 1];
            s[j * n + k] = k;
            for (int l = 0; l < k; l++)
            {
                double t = m[j * n + k - 1] + m[(k + 1) * n + l];
                if (t < m[j * n + k])
                {
                    m[j * n + k] = t;
                    s[j * n + k] = l;
                }
            }
            m[j * n + k] += w[i * n + k];
        }
    }
}

void printI(int *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", m[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printD(double *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", m[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    double a[] = {0.16, 0.02, 0.02, 0.05, 0.06, 0.01};
    double b[] = {0.1, 0.3, 0.1, 0.2, 0.1};
    double w[6][6], m[6][6];
    int s[6][6];

    Dp_BestSearchBinaryTree(6, a, b, (double *)w, (double *)m, (int *)s);
    printf("w: \n");
    printD(w, N);
    printf("\nm: \n");
    printD(m, N);
    printf("\ns: \n");
    printI(s, N);
    return 0;
}
