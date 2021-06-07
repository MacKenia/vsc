#include<stdio.h>
#include<math.h>

int main()
{
    int wDY(double vs, double r, double c);
    double vs, r, c;
    int n, i;
    scanf("%lf%lf%lf%d", &vs, &r, &c, &n);
    for (i = 0; i < n; i++) wDY(vs, r, c);
    return 0;
}

int wDY(double vs, double r, double c)
{
    double w, vr;
    scanf("%lf", &w);
    vr = w*vs*r*c*sqrt(1.0/(pow(r*c*w, 2.0)+1.0));
    printf("%.3lf\n", vr);
    return 0;
}
