#include <stdio.h>

void datasort(int score[], int n) /*datascort()函数定义*/
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (score[j] > score[i]) /*按数组score的元素值从高到低排序*/
            {
                temp = score[j];
                score[j] = score[i];
                score[i] = temp;
            }
        }
    }
}

int main()
{
    int score[10];
    for (int i = 0; i < 10; i++) scanf("%d",&score[i]);
    datasort(score,10);
    printf("\n%d\n",score[0]);
    for(int i = 0; i < 10; i++) printf("%d ",score[i]);
    return 0;
}