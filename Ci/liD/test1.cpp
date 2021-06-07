#include <stdio.h>

int main()
{
    double arr[4][5];
    int i, j;
    printf("请输入一个4乘5的矩阵：\n");
    for(i = 0;i < 4; i++)
        for(j = 0; j < 5; j++)
        {
            printf("请输入a[%d][%d]：",i+1,j+1);
            scanf("%lf",&arr[i][j]);
        }
    for(i = 0; i < 4; i++)
        for(j = 0; j < 5; j++)
        {
            if(arr[i][j] < 0) printf("第%d行%d列的元素%.2f小于0\n",i+1,j+1,arr[i][j]);
        }
    return 0;
}
