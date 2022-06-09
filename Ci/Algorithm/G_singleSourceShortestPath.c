#include <stdio.h>
#define I 65536

int n = 5;
int s[1000 * 1000] = {I, 10, I, 30, 100,
                      I, I, 50, I, I,
                      I, I, I, I, 10,
                      I, I, 20, I, 60,
                      I, I, I, I, I};

void Dijkstra(int *o)
{
    int count = 1;
    int best = 0;
    // 第一行赋值
    for (int i = 0; i < n; i++)
        o[i] = s[i];
    o[0] = I;

    // 开始计算
    while (count != n)
    {
        for (int i = 0; i < n - 1; i++)
            if (o[(count-1) * n + i] < o[(count-1) * n + i + 1])
                best = i;
        for (int i = 0; i < n; i++)
        {
            // 到下一个点的距离 上一个之前累计的距离 上一次计算的距离
            if (s[best * n + i] + o[count * n + best] < o[(count - 1) * n + i])
                o[count * n + i] = s[best * n + i] + o[count * n + best];
            else
                o[count * n + i] = o[(count - 1) * n + i];
        }
        count++;
    }
}

void init()
{
    printf("输入顶点个数: ");
    scanf("%d", &n);
    printf("%d", n);
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", (s + i));
        if (*(s + i) == -1)
            *(s + i) = I;
    }
}

int main()
{
    // init();
    int o[n*n];
    Dijkstra(s);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", s[i * n + j]);
        }
        printf("\n");
    }
    return 0;
}
