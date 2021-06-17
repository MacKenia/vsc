#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    getchar();
    int x, y, a, b;
    double sum = 0;
    for (int i = 0; i < 10; i++)
    {
        x = rand() % 101;
        y = rand() % 101;
        printf("(%d,%d)",x,y);
        getchar();
        if(!i) continue;
        sum += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        a = x;
        b = y;
    }
    printf("sum = %.3f\n", sum);
    return 0;
}
