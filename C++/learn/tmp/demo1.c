#include <stdio.h>

int main()
{
    int n, i, sum = 0; //定义上限n，循环量i，值sum并初始化
    printf("Input n:"); //输出提示信息
    scanf("%d", &n); //输入上限n
    for (i = 1; i <= n; i++) sum += i; //利用循环一直累加
    printf("sum = %d\n", sum); //输出答案
    return 0;
}
