//                .-~~~~~~~~~-._       _.-~~~~~~~~~-.
//            __.'              ~.   .~              `.__
//          .'//                  \./                  \\`.
//        .'//                     |                     \\`.
//      .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \\`.
//    .'//.-"                 `-.  |  .-'                 "-.\\`.
//  .'//______.============-..   \ | /   ..-============.______\\`.
//.'______________________________\|/______________________________`.
#include<stdio.h>

int main()
{
    int nack(double a, double b);
    double v, v0;
    for(;;)
    {
        scanf("%d%d", &v, &v0);
        if(v == 0&&v0 ==0) break;
        nack(v, v0);
    }
    return 0;
}

int nack(double a, double b)
{
    double n;
    if(a<b)
    {
        printf("0\n");
        return 0;
    }
    n = a/(2*b);
    if(n - (int) n == 0.5) printf("0\n");
    else if(n - (int) n < 0.5) printf("%d\n",(int) n);
    else printf("%d\n", (int)n+0.5);
    return 0;
}