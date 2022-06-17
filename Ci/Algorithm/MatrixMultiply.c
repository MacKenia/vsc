#include <stdio.h>
#include <string.h>

#define N 6

void matrix_chain(int *p, int n, int *m, int *s)
{
    // init matrix
    memset(m, 0, sizeof(int)*n*n);
    memset(s, 0, sizeof(int)*n*N);
    // processing
    for(int i = 1; i < n; i++)
    {
        for(int j = 0, k = i; j < n && k < n; j++,k++)
        {
            m[n*j+k] = m[n*(j+1)+k] + p[j]*p[j+1]*p[k+1];
            s[n*j+k] = j+1;
            for (int l = j+1; l < k; l++)
            {
                int t = m[n*j+l] + m[n*(l+1)+k] + p[j]*p[l+1]*p[k+1];
                if (t < m[n*j+k])
                {
                    m[n*j+k] = t;
                    s[n*j+k] = l+1;
                }
            };
        }
    }
}

void trace_back(int i, int j, int *s, int n)
{
    j--;
    if(i >= j)
        return;
    trace_back(i, s[n*i+j], s, n);
    trace_back(s[i*n+j]+1, j, s, n);
    printf("Multiply A %d, %d and A %d, %d\n", i+1, s[i*n+j]+1, s[i*n+j]+2, j+1);
}

int main()
{
    int m[N][N], s[N][N];
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    for (int i = 0; i < 7; i++)
    {
        scanf("%d",&p[i]);
    }
    matrix_chain(p, N, (int*)m, (int*)s);
    trace_back(0, N, (int *)s, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
