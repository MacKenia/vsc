#include <stdio.h>
int main()
{
	int i,n,sum=0,count=0;
	printf("Input a number:");
	for (i=1;;i++)
	{
		scanf("%d",&n);
		if(n > 0)
		{
			sum = sum + n;
			count=count+1;

		}
		if(n < 0)
		{
			continue;
		}
		if(n == 0)
		{
			break;
		}
	}
	printf("sum = %d, count = %d\n",sum,count);
	return 0 ;
 
}