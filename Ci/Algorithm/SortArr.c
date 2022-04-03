#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InsertSort(int, int*);
void BubbleSort(int, int*);
void SelectSort(int, int*);
void HillSort(int, int*);
void MergeSort(int, int*);
void QuickSort(int*, int, int);

int main()
{
    int N, arr[10]={9,8,6,6,5,4,3,2,1,0};
    // scanf("%d", &N);
    // for (int i = 0; i < N; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    N = 10;
    QuickSort(arr, 0, N-1);
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

void SelectSort(int N, int *p)
{
    int f = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if(p[f] > p[j]) f = j;
        }
        int t = p[f];
        p[f] = p[i];
        p[i] = t;
    }
    
}

void MergeSort(int N, int *p)
{
    int *tmp = (int*)malloc(sizeof(int) * N);
    for (int i = 1; i < N; i*=2)
    {
        memcpy(tmp, p, sizeof(int) * N);
        for(int j = 0; j < N; j+=i*2)
        {
            int k = j;
            int l = j + i >= N ? N : j + i;
            int m = j;
            int n = j + i * 2 >= N ? N : j + i * 2;
            while(k < j + i && l < n)
            {
                if(tmp[k] > tmp[l])
                {
                    p[m++] = tmp[l++];
                }
                else
                {
                    p[m++] = tmp[k++];
                }
            }
            while(k < j + i)
            {
                p[m++] = tmp[k++];
            }
            while (l < n)
            {
                p[m++] = tmp[l++];
            }
            {
                p[m++] = tmp[l++];
            }
        }
        
    }
    free(tmp);
}

void QuickSort(int *p, int start, int end)
{
    if(start >= end) return;
    int i = start, j = end;
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
    QuickSort(p, start, i-1);
    QuickSort(p, i, end);
}