#include <stdio.h>
#include <string.h>

#define N 6

void matrix_chain(int *p, int n, int **m, int **s)
{
    // init matrix
    memset(m, 0, sizeof(int)*n*n);
    for (int i = 1; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            int k = j + 1;
            m[j][k] = m[j + 1][k] + p[j - 1] * p[j] * p[k];
            s[j][k] = j;
            for (int l = i + 1; l < k; l++)
            {
                int t = m[i][l] + m[l + 1][k] + p[j - 1] * p[l] * p[k];
                if (t < m[j][k])
                {
                    m[j][k] = t;
                    s[j][k] = l;
                }
            }
        }
}

void trace_back(int i, int j, int **s)
{
    if(i == j)
        return;
    trace_back(i, s[i][j], s);
    trace_back(s[i][j+1], j, s);
    printf("Multiply A %d, %d and A %d, %d\n", i, s[i][j], s[i][j]+1, j);
}

int main()
{
    int m[N][N], s[N][N];
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    for (int i = 0; i < 0; i++)
    {
        scanf("%d",&p[i]);
    }
    matrix_chain(p, N, (int **)m, (int **)s);
    trace_back(0, N, (int **)s);
    return 0;
}
