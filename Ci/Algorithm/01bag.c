#include <stdio.h>
#include <string.h>

int goods[2][5] = {{0, 2, 3, 4, 5}, {0, 3, 4, 5, 8}};

int arr[5][9] = {0};

int max(int a, int b)
{
    return a >= b ? a : b;
}

int main()
{
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (goods[0][i] > j)
            {
                arr[i][j] = arr[i - 1][j];
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - goods[0][i]] + goods[1][i]);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("最优值为：%d\n", arr[4][8]);

    // 回溯
    for (int i = 3; i > 0; i--)
    {
        for (int j = 8; j > 0; j--)
        {
            if (arr[i][j] == arr[i - 1][j])
            {
                printf("%d\t", i);
                j -= goods[0][i];
            }
        }
    }

    return 0;
}
