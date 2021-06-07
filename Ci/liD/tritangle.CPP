//输入逗号没看到
#include <math.h>
#include <stdio.h>
int main()

{  
	float a,b,c;
	int flag=1;
	printf("Input the three edge length: ");
	scanf("%f,%f,%f",&a,&b,&c);
	if (a+b>c&&a+c>b&&b+c>a)
	{
		
		if (fabs(a-b)<=1e-1||fabs(a-c)<=1e-1||fabs(b-c)<=1e-1)
		{
			printf("等腰");
			flag=0;
		}
		if(fabs(a*a-b*b+c*c)<=1e-1||fabs(b*b-a*a+c*c)<=1e-1||fabs(b*b-c*c+a*a)<=1e-1)
		{
			printf("直角");
			flag=0;
		}
		if (flag)
		{
			printf("一般");
		}
		printf("三角形\n");	
	}
	else 
	{
		printf("不是三角形\n");
	}
	return 0;
}