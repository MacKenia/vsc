#include<stdio.h>
#include<math.h>

int main()
{
    double culculate(double wA, double jA, double wB, double jB);
    double a, b, c;
    double wA, jA, wB, jB;
    int i;
    char rb[80];

    //前面的三行
    for (i = 0; i < 3; i++) gets(rb);

    //船的第一个坐标
    scanf("%lf^%lf'%lf\" %s", &a, &b, &c, rb);
    wA = a + b/60 + c/3600;
    if (rb[0] == 'S') wA *= -1;

    //and
    scanf("%s", rb);

    //船的第二个坐标
    scanf("%lf^%lf'%lf\" %s", &a, &b, &c, rb);
    jA = a + b/60 + c/3600;
    if (rb[0] == 'W') jA *= -1;

    //中间的无用信息
    for(i = 0; i < 5; i++) scanf("%s", rb);

    //冰川的第一个坐标
    scanf("%lf^%lf'%lf\" %s", &a, &b, &c, rb);
    wB = a + b/60 + c/3600;
    if (rb[0] == 'S') wB *= -1;

    //and
    scanf("%s", rb);

    //冰川的第二个坐标
    scanf("%lf^%lf'%lf\" %s", &a, &b, &c, rb);
    jB = a + b/60 + c/3600;
    if (rb[0] == 'W') jB *= -1;

    //无用信息
    scanf("%s", rb);

    //开始计算
    a = culculate(wA, jA, wB, jB);

    //输出距离
    printf("The distance to the iceberg: %.2lf miles.\n", a);

    //判断是否小于100英里
    if(floor(a + 0.005) < 100) printf("DANGER!\n");
    return 0;
}
//距离的计算函数
double culculate(double wA, double jA, double wB, double jB)
{
    double r = 3437.5;
    double pi = acos(-1.0);
    wA *= pi/180;wB *= pi/180;
    jA *= pi/180;jB *= pi/180;
    return r*acos(cos(wA)*cos(wB)*cos(jA-jB)+sin(wA)*sin(wB));
}