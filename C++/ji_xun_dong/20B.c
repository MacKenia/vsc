#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793

int main()
{
    double a;
    while (~scanf("%lf", &a))
    {
        double z=a*a-pi*a*a/6.0-sqrt(3)/4.0*a*a;
        double y=a*a-pi*a*a/4.0-2.0*z;
        double x=a*a-4.0*y-4.0*z;
        printf("%.3lf %.3lf %.3lf\n",x,4*y,4*z);
    }
    
    return 0;
}




