#include <stdio.h>

void sort(int, int*);

int main()
{
    int N, arr[10];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(N, arr);
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    return 1;
}

void sort(int N, int *p)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(p[i] <= p[j])
            {
                int t = p[i];
                for (int k = i; k > j; k--)
                {
                    p[k] = p[k-1];
                }
                p[j] = t;
                break;
            }
        }
        
    }
    
}
