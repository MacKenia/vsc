#include <stdio.h>

void InsertSort(int, int*);
void BubbleSort(int, int*);

int main()
{
    int N, arr[10];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    BubbleSort(N, arr);
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 1;
}

void BubbleSort(int N, int *p)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - i ; j++)
        {
            if(p[j] >= p[j+1])
            {
                int t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
}

void InsertSort(int N, int *p)
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
